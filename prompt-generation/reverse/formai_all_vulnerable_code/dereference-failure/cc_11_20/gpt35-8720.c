//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type;

typedef struct json_value_t{
    json_type type;
    union{
        char *string_val;
        double number_val;
        struct json_value_t *node_val;
    } val;
    int num_nodes; //number of child nodes if it is a JSON_OBJECT or JSON_ARRAY type
} json_value;

json_value *parse_json(char *json_str);

void print_json(json_value *json);

int main(){
    char *json_str = "{\"name\":\"John Smith\",\"age\":30,\"isMarried\":true}";
    json_value *json_object = parse_json(json_str);
    print_json(json_object);
    free(json_object);
    return 0;
}

json_value *parse_json(char *json_str){
    json_value *root = malloc(sizeof(json_value));
    char *p = json_str;
    if(*p == '{'){ //if it is an object
        root->type = JSON_OBJECT;
        root->num_nodes = 0;
        json_value *cur_node = NULL;
        //parse object
        p++; //skip the opening brace
        while(*p != '}'){
            json_value *node = malloc(sizeof(json_value));
            //parse property
            p++; //skip white spaces
            //parse key
            char *key_start = p;
            while(*p != ':'){
                p++;
            }
            char *key_end = p;
            *key_end = '\0';
            node->val.string_val = strdup(key_start);
            node->type = JSON_STRING;
            //parse value
            p++; //skip the colon
            p++; //skip white spaces
            if(*p == '['){ //array
                node->type = JSON_ARRAY;
                node->num_nodes = 0;
                p++; //skip opening bracket
                while(*p != ']'){
                    if(*p == ','){
                        p++; //skip comma
                    }
                    if(*p == '{' || *p == '['){ //nested object or array
                        json_value *child = parse_json(p);
                        p += (child->num_nodes + 2); //add 2 to account for closing brace or bracket and trailing comma if present
                        node->num_nodes++;
                        node->val.node_val = realloc(node->val.node_val, sizeof(json_value) * node->num_nodes);
                        node->val.node_val[node->num_nodes-1] = *child;
                        free(child);
                    }else if(*p == '\"'){ //string
                        char *start = p+1;
                        while(*p != '\"'){
                            p++;
                        }
                        char *end = p;
                        *end = '\0';
                        node->num_nodes++;
                        node->val.string_val = realloc(node->val.string_val, sizeof(char) * strlen(start) + 1);
                        node->val.string_val[node->num_nodes-1] = strdup(start);
                    }else if(*p == 't'){ //true
                        node->num_nodes++;
                        node->val.node_val = realloc(node->val.node_val, sizeof(json_value) * node->num_nodes);
                        node->val.node_val[node->num_nodes-1].type = JSON_TRUE;
                        node->val.node_val[node->num_nodes-1].num_nodes = 0;
                        p += 3;
                    }else if(*p == 'f'){ //false
                        node->num_nodes++;
                        node->val.node_val = realloc(node->val.node_val, sizeof(json_value) * node->num_nodes);
                        node->val.node_val[node->num_nodes-1].type = JSON_FALSE;
                        node->val.node_val[node->num_nodes-1].num_nodes = 0;
                        p += 4;
                    }else if(*p == 'n'){ //null
                        node->num_nodes++;
                        node->val.node_val = realloc(node->val.node_val, sizeof(json_value) * node->num_nodes);
                        node->val.node_val[node->num_nodes-1].type = JSON_NULL;
                        node->val.node_val[node->num_nodes-1].num_nodes = 0;
                        p += 3;
                    }else{ //number
                        char *start = p;
                        double num = strtod(start, &p);
                        node->num_nodes++;
                        node->val.node_val = realloc(node->val.node_val, sizeof(json_value) * node->num_nodes);
                        node->val.node_val[node->num_nodes-1].type = JSON_NUMBER;
                        node->val.node_val[node->num_nodes-1].val.number_val = num;
                    }
                }
                p++; //skip closing bracket
            }else if(*p == '{'){ //object
                node->type = JSON_OBJECT;
                node->num_nodes = 0;
                p++; //skip opening brace
                while(*p != '}'){
                    if(*p == ','){
                        p++; //skip comma
                    }
                    if(*p == '\"'){ //property
                        json_value *child = malloc(sizeof(json_value));
                        char *key_start = p+1;
                        while(*p != ':'){
                            p++;
                        }
                        char *key_end = p;
                        *key_end = '\0';
                        child->type = JSON_STRING;
                        child->num_nodes = 1;
                        child->val.string_val = strdup(key_start);
                        p++; //skip colon
                        p++; //skip white spaces
                        if(*p == '[' || *p == '{'){ //nested array or object
                            json_value *nested_node = parse_json(p);
                            child->num_nodes++;
                            child->val.node_val = realloc(child->val.node_val, sizeof(json_value) * child->num_nodes);
                            child->val.node_val[child->num_nodes-1] = *nested_node;
                            free(nested_node);
                        }else if(*p == '\"'){ //string
                            char *start = p+1;
                            while(*p != '\"'){
                                p++;
                            }
                            char *end = p;
                            *end = '\0';
                            child->val.string_val = realloc(child->val.string_val, sizeof(char) * strlen(start) + 1);
                            child->val.string_val[0] = '\0';
                            strcat(child->val.string_val, start);
                        }else if(*p == 't'){ //true
                            child->val.node_val = malloc(sizeof(json_value));
                            child->val.node_val->type = JSON_TRUE;
                            child->val.node_val->num_nodes = 0;
                            p += 3;
                        }else if(*p == 'f'){ //false
                            child->val.node_val = malloc(sizeof(json_value));
                            child->val.node_val->type = JSON_FALSE;
                            child->val.node_val->num_nodes = 0;
                            p += 4;
                        }else if(*p == 'n'){ //null
                            child->val.node_val = malloc(sizeof(json_value));
                            child->val.node_val->type = JSON_NULL;
                            child->val.node_val->num_nodes = 0;
                            p += 3;
                        }else{ //number
                            char *start = p;
                            double num = strtod(start, &p);
                            child->val.node_val = malloc(sizeof(json_value));
                            child->val.node_val->type = JSON_NUMBER;
                            child->val.node_val->val.number_val = num;
                        }
                        node->num_nodes++;
                        node->val.node_val = realloc(node->val.node_val, sizeof(json_value) * node->num_nodes);
                        node->val.node_val[node->num_nodes-1] = *child;
                        free(child);
                    }
                }
                p++; //skip closing brace
            }else if(*p == '\"'){ //string
                char *start = p+1;
                while(*p != '\"'){
                    p++;
                }
                char *end = p;
                *end = '\0';
                node->type = JSON_STRING;
                node->val.string_val = strdup(start);
            }else if(*p == 't'){ //true
                node->type = JSON_TRUE;
            }else if(*p == 'f'){ //false
                node->type = JSON_FALSE;
            }else if(*p == 'n'){ //null
                node->type = JSON_NULL;
            }else{ //number
                char *start = p;
                double num = strtod(start, &p);
                node->type = JSON_NUMBER;
                node->val.number_val = num;
            }
            if(cur_node == NULL){ //first node
                root->num_nodes++;
                root->val.node_val = realloc(root->val.node_val, sizeof(json_value) * root->num_nodes);
                root->val.node_val[root->num_nodes-1] = *node;
                cur_node = root->val.node_val + root->num_nodes-1;
            }else{ //nested node
                cur_node->num_nodes++;
                cur_node->val.node_val = realloc(cur_node->val.node_val, sizeof(json_value) * cur_node->num_nodes);
                cur_node->val.node_val[cur_node->num_nodes-1] = *node;
                cur_node = cur_node->val.node_val + cur_node->num_nodes-1;
            }
            free(node);
        }
        p++; //skip closing brace
    }else{ //if it is an array
        root->type = JSON_ARRAY;
        root->num_nodes = 0;
        json_value *cur_node = NULL;
        //parse array
        p++; //skip opening bracket
        while(*p != ']'){
            if(*p == ','){
                p++; //skip comma
            }
            json_value *node = malloc(sizeof(json_value));
            node->type = JSON_NULL;
            node->num_nodes = 0;
            if(*p == '{' || *p == '['){ //nested object or array
                json_value *child = parse_json(p);
                if(child->num_nodes > 0){
                    node->type = child->type;
                    node->num_nodes = child->num_nodes;
                    node->val.node_val = malloc(sizeof(json_value) * child->num_nodes);
                    for(int i = 0; i < child->num_nodes; i++){
                        node->val.node_val[i] = child->val.node_val[i];
                    }
                }
                p += (child->num_nodes + 2); //add 2 to account for closing brace or bracket and trailing comma if present
                free(child);
            }else if(*p == '\"'){ //string
                char *start = p+1;
                while(*p != '\"'){
                    p++;
                }
                char *end = p;
                *end = '\0';
                node->type = JSON_STRING;
                node->val.string_val = strdup(start);
            }else if(*p == 't'){ //true
                node->type = JSON_TRUE;
            }else if(*p == 'f'){ //false
                node->type = JSON_FALSE;
            }else if(*p == 'n'){ //null
                node->type = JSON_NULL;
            }else{ //number
                char *start = p;
                double num = strtod(start, &p);
                node->type = JSON_NUMBER;
                node->val.number_val = num;
            }
            if(cur_node == NULL){ //first node
                root->num_nodes++;
                root->val.node_val = realloc(root->val.node_val, sizeof(json_value) * root->num_nodes);
                root->val.node_val[root->num_nodes-1] = *node;
                cur_node = root->val.node_val + root->num_nodes-1;
            }else{ //nested node
                cur_node->num_nodes++;
                cur_node->val.node_val = realloc(cur_node->val.node_val, sizeof(json_value) * cur_node->num_nodes);
                cur_node->val.node_val[cur_node->num_nodes-1] = *node;
                cur_node = cur_node->val.node_val + cur_node->num_nodes-1;
            }
            free(node);
        }
        p++; //skip closing bracket
    }
    root->num_nodes++; //add 1 for the root node
    return root;
}

void print_json(json_value *json){
    if(json == NULL){
        printf("null");
        return;
    }
    switch(json->type){
        case JSON_OBJECT:
            printf("{");
            for(int i = 0; i < json->num_nodes-1; i++){
                printf("\"%s\":", json->val.node_val[i].val.string_val);
                print_json(&json->val.node_val[i+1]);
                printf(",");
            }
            if(json->num_nodes > 1){ //remove extra comma
                printf("\"%s\":", json->val.node_val[json->num_nodes-1].val.string_val);
                print_json(&json->val.node_val[json->num_nodes]);
                printf("}");
            }else{
                printf("}");
            }
            break;
        case JSON_ARRAY:
            printf("[");
            for(int i = 0; i < json->num_nodes-1; i++){
                print_json(&json->val.node_val[i]);
                printf(",");
            }
            if(json->num_nodes > 0){ //remove extra comma
                print_json(&json->val.node_val[json->num_nodes-1]);
                printf("]");
            }else{
                printf("]");
            }
            break;
        case JSON_STRING:
            printf("\"%s\"", json->val.string_val);
            break;
        case JSON_NUMBER:
            printf("%lf", json->val.number_val);
            break;
        case JSON_TRUE:
            printf("true");
            break;
        case JSON_FALSE:
            printf("false");
            break;
        case JSON_NULL:
            printf("null");
            break;
    }
}