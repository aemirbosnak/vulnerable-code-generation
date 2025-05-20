//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_OBJECT_LIMIT 10
#define JSON_ELEMENT_LIMIT 100

typedef enum {
    JSON_ARRAY,
    JSON_OBJECT,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} json_type;

typedef struct {
    char *key;
    json_type type;
    void *value;
} json_element;

typedef struct {
    json_type type;
    int length;
    json_element *elements;
} json_value;

json_value *parse_object(char *);

json_value *parse_array(char *);

json_value *parse_value(char *);

json_value *parse_string(char *);

json_value *parse_number(char *);

json_value *parse_bool(char *);

json_value *parse_null(char *);

void free_json(json_value *);

int indent_level = 0;
#define TAB_SIZE 4

void print_indent() {
    for (int i = 0; i < indent_level * TAB_SIZE; i++) {
        putchar(' ');
    }
}

void print_json(json_value *json) {
    if (!json) return;

    switch (json->type) {
        case JSON_OBJECT:
            printf("{\n");
            indent_level++;
            for (int i = 0; i < json->length; i++) {
                print_indent();
                printf("\"%s\" : ", json->elements[i].key);
                print_json((json_value *) json->elements[i].value);
                if (i < json->length - 1) printf(",");
                putchar('\n');
            }
            indent_level--;
            print_indent();
            printf("}");
            break;
        case JSON_ARRAY:
            printf("[\n");
            indent_level++;
            for (int i = 0; i < json->length; i++) {
                print_indent();
                print_json((json_value *) json->elements[i].value);
                if (i < json->length - 1) printf(",");
                putchar('\n');
            }
            indent_level--;
            print_indent();
            printf("]");
            break;
        case JSON_STRING:
            printf("\"%s\"", (char *) json->elements[0].value);
            break;
        case JSON_NUMBER:
            printf("%s", (char *) json->elements[0].value);
            break;
        case JSON_BOOL:
            printf("%s", *(int *) json->elements[0].value ? "true" : "false");
            break;
        case JSON_NULL:
            printf("null");
            break;
        default:
            printf("Unknown type");
    }
}


json_value *parse_object(char *json_str) {
    if (*json_str++ != '{') {
        printf("Error: Expected '{' at beginning of object");
        return NULL;
    }
    
    int num_elements = 0;
    json_element elements[JSON_ELEMENT_LIMIT];

    while (*json_str && *json_str != '}') {
        if (*json_str == '"') {
            char key[1024];
            int nread = sscanf(json_str, "\"%[^\"]", key);
            json_str += nread + 1;
            if (*json_str++ != ':') {
                printf("Error: Expected ':' after key");
                return NULL;
            }
            
            json_value *value = parse_value(json_str);
            if (!value) return NULL;
            
            elements[num_elements].key = strdup(key);
            elements[num_elements].type = value->type;
            elements[num_elements].value = value;
            num_elements++;
            
            if (*json_str == ',') json_str++;
        }
        else if (*json_str == ',') {
            printf("Error: Unexpected comma");
            return NULL;
        }
        else {
            json_str++;
        }
    }
    
    if (*json_str == '}') json_str++;
    
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_OBJECT;
    result->length = num_elements;

    result->elements = malloc(num_elements * sizeof(json_element));
    memcpy(result->elements, elements, num_elements * sizeof(json_element));
    
    return result;
}

json_value *parse_array(char *json_str) {
    if (*json_str == '[') json_str++;
    else {
        printf("Error: Expected '[' at beginning of array");
        return NULL;
    }
    
    int num_elements = 0;
    json_element elements[JSON_ELEMENT_LIMIT];
    
    while (*json_str && *json_str != ']') {
        json_value *value = parse_value(json_str);
        if (!value) return NULL;
        
        elements[num_elements].key = NULL;
        elements[num_elements].type = value->type;
        elements[num_elements].value = value;
        num_elements++;
        
        if (*json_str == ',') json_str++;
    }
    
    if (*json_str == ']') json_str++;
    
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_ARRAY;
    result->length = num_elements;

    result->elements = malloc(num_elements * sizeof(json_element));
    memcpy(result->elements, elements, num_elements * sizeof(json_element));
    
    return result;
}

json_value *parse_value(char *json_str) {
    json_value *result = NULL;

    while (*json_str == ' ' || *json_str == '\n' || *json_str == '\r' || *json_str == '\t')
        json_str++;

    if (*json_str == '{') result = parse_object(json_str);
    else if (*json_str == '[') result = parse_array(json_str);
    else if (*json_str == '"') result = parse_string(json_str);
    else if (*json_str >= '0' && *json_str <= '9') result = parse_number(json_str);
    else if (*json_str == 't' || *json_str == 'f') result = parse_bool(json_str);
    else if (*json_str == 'n') result = parse_null(json_str);
    else printf("Error: Unexpected character");

    return result;
}

json_value *parse_string(char *json_str) {
    if (*json_str == '"') json_str++;
    else {
        printf("Error: Expected '\"' at beginning of string");
        return NULL;
    }
    
    char string[1024];
    int nread = sscanf(json_str, "%[^\"]\"", string);
    if (nread <= 0) {
        printf("Error: Failed to read string");
        return NULL;
    }
    json_str += nread + 1;
    
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_STRING;
    result->length = 1;

    result->elements = malloc(sizeof(json_element));
    result->elements[0].key = NULL;
    result->elements[0].type = JSON_STRING;
    result->elements[0].value = strdup(string);
    
    return result;
}

json_value *parse_number(char *json_str) {
    char number[1024];
    int nread = sscanf(json_str, "%[^,}]%*[,}]", number);
    if (nread <= 0) {
        printf("Error: Failed to read number");
        return NULL;
    }
    json_str += nread;
    
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_NUMBER;
    result->length = 1;

    result->elements = malloc(sizeof(json_element));
    result->elements[0].key = NULL;
    result->elements[0].type = JSON_NUMBER;
    result->elements[0].value = strdup(number);
    
    return result;
}

json_value *parse_bool(char *json_str) {
    char bool_str[6];
    int nread = sscanf(json_str, "%5s", bool_str);
    if (nread <= 0) {
        printf("Error: Failed to read boolean");
        return NULL;
    }
    json_str += nread;
    int bool_result = !strncmp(bool_str, "true", 4);
    
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_BOOL;
    result->length = 1;

    result->elements = malloc(sizeof(json_element));
    result->elements[0].key = NULL;
    result->elements[0].type = JSON_BOOL;
    result->elements[0].value = malloc(sizeof(int));
    *(int *) result->elements[0].value = bool_result;
    
    return result;
}

json_value *parse_null(char *json_str) {
    char null_str[6];
    int nread = sscanf(json_str, "%5s", null_str);
    if (nread <= 0 || strncmp(null_str, "null", 4)) {
        printf("Error: Failed to read null");
        return NULL;
    }
    json_str += nread;
    
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_NULL;
    result->length = 0;

    result->elements = NULL;
    
    return result;
}

void free_json(json_value *json) {
    if (!json) return;

    for (int i = 0; i < json->length; i++) {
        if (json->elements[i].type == JSON_OBJECT || json->elements[i].type == JSON_ARRAY)
            free_json((json_value *) json->elements[i].value);
        else if (json->elements[i].value)
            free(json->elements[i].value);
        if (json->elements[i].key)
            free(json->elements[i].key);
    }
    if (json->elements) free(json->elements);
    free(json);
}

int main() {
    char *json_str = "{\n"
                     "    \"firstName\": \"John\",\n"
                     "    \"lastName\": \"Smith\",\n"
                     "    \"age\": 25,\n"
                     "    \"address\": {\n"
                     "        \"streetAddress\": \"21 2nd Street\",\n"
                     "        \"city\": \"New York\",\n"
                     "        \"state\": \"NY\",\n"
                     "        \"postalCode\": 10021\n"
                     "    },\n"
                     "    \"phoneNumbers\": [\n"
                     "        {\n"
                     "            \"type\": \"home\",\n"
                     "            \"number\": \"212 555-1234\"\n"
                     "        },\n"
                     "        {\n"
                     "            \"type\": \"fax\",\n"
                     "            \"number\": \"646 555-4567\"\n"
                     "        }\n"
                     "    ]\n"
                     "}";

    json_value *json = parse_object(json_str);
    printf("JSON:\n");
    print_json(json);
    putchar('\n');
    free_json(json);

    return 0;
}