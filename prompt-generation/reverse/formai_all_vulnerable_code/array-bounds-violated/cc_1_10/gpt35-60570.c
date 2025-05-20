//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON 2048

typedef enum {
    JSON_OBJECT = 1,
    JSON_ARRAY  = 2,
    JSON_BOOL   = 3,
    JSON_NULL   = 4,
    JSON_NUMBER = 5,
    JSON_STRING = 6
} json_type;

typedef struct {
    json_type type;
    union {
        char *string;
        double number;
        int boolean;
    } val;
} json_value;

json_value *parse_value(char *json_str);

json_value *parse_object(char *json_str) {
    json_value *obj = malloc(sizeof(json_value));
    obj->type = JSON_OBJECT;
    // TODO
    return obj;
}

json_value *parse_array(char *json_str) {
    json_value *arr = malloc(sizeof(json_value));
    arr->type = JSON_ARRAY;
    // TODO
    return arr;
}

json_value *parse_bool(char *json_str) {
    json_value *boo = malloc(sizeof(json_value));
    boo->type = JSON_BOOL;
    if (strncmp(json_str, "true", 4) == 0) {
        boo->val.boolean = 1;
    } else if (strncmp(json_str, "false", 5) == 0) {
        boo->val.boolean = 0;
    } else {
        printf("Error: invalid boolean value\n");
        exit(1);
    }
    return boo;
}

json_value *parse_null(char *json_str) {
    json_value *nul = malloc(sizeof(json_value));
    nul->type = JSON_NULL;
    if (strncmp(json_str, "null", 4) != 0) {
        printf("Error: invalid null value\n");
        exit(1);
    }
    return nul;
}

json_value *parse_number(char *json_str) {
    json_value *num = malloc(sizeof(json_value));
    num->type = JSON_NUMBER;
    num->val.number = strtod(json_str, &json_str);
    return num;
}

json_value *parse_string(char *json_str) {
    json_value *str = malloc(sizeof(json_value));
    str->type = JSON_STRING;
    char *s = json_str;
    while (*s != '\"') {
        if (*s == '\0') {
            printf("Error: invalid string value\n");
            exit(1);
        }
        if (*s == '\\') s++;
        s++;
    }
    size_t len = s - json_str - 1;
    str->val.string = malloc(len + 1);
    memcpy(str->val.string, json_str + 1, len);
    str->val.string[len] = '\0';
    return str;
}

json_value *parse_value(char *json_str) {
    json_value *val;
    json_str += strspn(json_str, " \t\r\n");
    switch (*json_str) {
    case '\0':
        printf("Error: empty input\n");
        exit(1);
    case '{': case '}':
        val = parse_object(json_str);
        break;
    case '[': case ']':
        val = parse_array(json_str);
        break;
    case 't': case 'f':
        val = parse_bool(json_str);
        break;
    case 'n':
        val = parse_null(json_str);
        break;
    case '\"':
        val = parse_string(json_str);
        break;
    default:
        if (isdigit(*json_str) || *json_str == '-') {
            val = parse_number(json_str);
        } else {
            printf("Error: invalid input\n");
            exit(1);
        }
    }
    return val;
}

void print_value(json_value *val) {
    switch (val->type) {
    case JSON_OBJECT:
        printf("object\n");
        break;
    case JSON_ARRAY:
        printf("array\n");
        break;
    case JSON_BOOL:
        printf(val->val.boolean ? "true\n" : "false\n");
        break;
    case JSON_NULL:
        printf("null\n");
        break;
    case JSON_NUMBER:
        printf("%lf\n", val->val.number);
        break;
    case JSON_STRING:
        printf("\"%s\"\n", val->val.string);
        break;
    }
}

int main() {
    char json_str[MAX_JSON];
    json_value *val;

    printf("Enter JSON: ");
    fgets(json_str, MAX_JSON, stdin);
    if (json_str[strlen(json_str) - 1] == '\n')
        json_str[strlen(json_str) - 1] = '\0';

    val = parse_value(json_str);
    print_value(val);

    return 0;
}