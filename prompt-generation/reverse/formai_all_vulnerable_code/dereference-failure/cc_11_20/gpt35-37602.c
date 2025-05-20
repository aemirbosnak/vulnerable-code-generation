//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef struct json_value_t {
    int type;
    char* key;
    char* value;
} json_value_t;

typedef struct json_t {
    int size;
    json_value_t* values;
} json_t;

json_t* json_parse(char* json_input) {
    json_t* json = (json_t*)malloc(sizeof(json_t));
    
    char* ptr = json_input;
    char* buffer = (char*)malloc(sizeof(char) * MAX_JSON_SIZE);
    int buffer_index = 0;
    int value_type = -1; // -1: not started, 0: string, 1: number, 2: boolean

    json->size = 0;
    json->values = (json_value_t*)malloc(sizeof(json_value_t));

    while(*ptr != '\0') {
        if(*ptr == '"') { // start of string value
            value_type = 0;
            ptr++; // skip the starting quote

            while(*ptr != '"' && *ptr != '\0') {
                buffer[buffer_index++] = *ptr;
                ptr++;
            }
            if(*ptr == '"') { // end of string value
                buffer[buffer_index] = '\0';

                if(json->size == 0) {
                    json->values[0].key = strdup(buffer);
                } else {
                    json->values = (json_value_t*)realloc(json->values, (json->size+1)*sizeof(json_value_t));
                    json->values[json->size].key = strdup(buffer);
                }

                buffer_index = 0;

                if(*(ptr+1) == ':') { // next is the value
                    ptr += 2;
                } else { // invalid json format
                    printf("Invalid JSON format!");
                    free(buffer);
                    free(json);
                    return NULL;
                }
            } else { // invalid json format
                printf("Invalid JSON format!");
                free(buffer);
                free(json);
                return NULL;
            }
        } else if(*ptr == ' ' || *ptr == '\n' || *ptr == '\r' || *ptr == '\t') { // ignore whitespace
            ptr++;
        } else if(*ptr == ':') { // start of value
            ptr++; // skip the colon
            while(*ptr != '\0') {
                if(value_type == 0) { // string value
                    if(*ptr == '"') { // end of string value
                        buffer[buffer_index] = '\0';
                        json->values[json->size].type = 0;
                        json->values[json->size].value = strdup(buffer);

                        buffer_index = 0;
                        value_type = -1;
                        json->size++;

                        if(*(ptr+1) == ',') { // there is another key-value pair
                            ptr += 2;
                        } else if(*(ptr+1) == '}') { // end of json object
                            free(buffer);
                            return json;
                        } else { // invalid json format
                            printf("Invalid JSON format!");
                            free(buffer);
                            free(json);
                            return NULL;
                        }
                    } else {
                        buffer[buffer_index++] = *ptr;
                        ptr++;
                    }
                } else if(value_type == -1) { // not started yet
                    if(*ptr == '"') { // start of string value
                        value_type = 0;
                        ptr++; // skip the starting quote
                    } else if((*ptr >= '0' && *ptr <= '9') || *ptr == '-') { // start of number value
                        value_type = 1;
                        buffer[buffer_index++] = *ptr;
                        ptr++;
                    } else if(strncmp(ptr, "true", 4) == 0) { // true boolean value
                        value_type = 2;
                        buffer[buffer_index++] = '1';
                        ptr += 4;
                    } else if(strncmp(ptr, "false", 5) == 0) { // false boolean value
                        value_type = 2;
                        buffer[buffer_index++] = '0';
                        ptr += 5;
                    } else if(*ptr == '{') { // start of another json object
                        value_type = -1;
                        buffer_index = 0;
                        json_t* inner_json = json_parse(ptr);
                        if(inner_json == NULL) { // invalid json format
                            printf("Invalid JSON format!");
                            free(buffer);
                            free(json);
                            return NULL;
                        }
                        json->values[json->size].type = 3; // json object type
                        json->values[json->size].value = (char*)inner_json;
                        json->size++;

                        while(*ptr++ != '\0') { // move pointer to the end of the inner json object
                            if(*ptr == '}' && (*(ptr+1) == ',' || *(ptr+1) == '\0')) { // there is another key-value pair
                                ptr++; // move pointer after the comma
                                break;
                            } else if(*ptr == '}') { // end of json object
                                free(buffer);
                                return json;
                            }
                        }
                    } else { // invalid json format
                        printf("Invalid JSON format!");
                        free(buffer);
                        free(json);
                        return NULL;
                    }
                } else if(value_type == 1) { // number value
                    if((*ptr >= '0' && *ptr <= '9') || *ptr == '.') {
                        buffer[buffer_index++] = *ptr;
                        ptr++;
                    } else {
                        buffer[buffer_index] = '\0';
                        json->values[json->size].type = 1;
                        json->values[json->size].value = strdup(buffer);

                        buffer_index = 0;
                        value_type = -1;
                        json->size++;

                        if(*ptr == ',') { // there is another key-value pair
                            ptr++;
                        } else if(*ptr == '}') { // end of json object
                            free(buffer);
                            return json;
                        } else { // invalid json format
                            printf("Invalid JSON format!");
                            free(buffer);
                            free(json);
                            return NULL;
                        }
                    }
                } else if(value_type == 2) { // boolean value
                    buffer[buffer_index++] = *ptr;
                    buffer[buffer_index] = '\0';
                    json->values[json->size].type = 2;
                    json->values[json->size].value = strdup(buffer);

                    buffer_index = 0;
                    value_type = -1;
                    json->size++;

                    if(*ptr == ',') { // there is another key-value pair
                        ptr++;
                    } else if(*ptr == '}') { // end of json object
                        free(buffer);
                        return json;
                    } else { // invalid json format
                        printf("Invalid JSON format!");
                        free(buffer);
                        free(json);
                        return NULL;
                    }
                }
            }
        } else {
            printf("Invalid JSON format!");
            free(buffer);
            free(json);
            return NULL;
        }
    }

    free(buffer);
    return json;
}

void json_free(json_t* json) {
    for(int i = 0; i < json->size; i++) {
        free(json->values[i].key);
        if(json->values[i].type == 0 || json->values[i].type == 1 || json->values[i].type == 2) {
            free(json->values[i].value);
        } else if(json->values[i].type == 3) {
            json_free((json_t*)json->values[i].value);
        }
    }
    free(json->values);
    free(json);
}

int main() {
    char input[] = "{\"name\":\"John\",\"age\":30,\"cars\":[\"Ford\",\"BMW\",\"Fiat\"],\"married\":true,\"address\":{\"street\":\"123 Main St\",\"city\":\"Chicago\",\"state\":\"IL\",\"zip\":60601}}";
    json_t* json = json_parse(input);
    if(json != NULL) {
        printf("Successfully parsed JSON!\n");

        for(int i = 0; i < json->size; i++) {
            printf("Key: %s\n", json->values[i].key);
            printf("Type: %d\n", json->values[i].type);
            if(json->values[i].type == 0 || json->values[i].type == 1 || json->values[i].type == 2) {
                printf("Value: %s\n", json->values[i].value);
            } else if(json->values[i].type == 3) {
                printf("Value: ");
                json_t* inner_json = (json_t*)json->values[i].value;
                for(int j = 0; j < inner_json->size; j++) {
                    printf("(%s, %s) ", inner_json->values[j].key, inner_json->values[j].value);
                }
                printf("\n");
            }
        }

        json_free(json);
    } else {
        printf("Failed to parse JSON!\n");
    }

    return 0;
}