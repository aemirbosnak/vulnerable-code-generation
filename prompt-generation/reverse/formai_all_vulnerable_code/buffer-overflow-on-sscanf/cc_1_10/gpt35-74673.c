//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_JSON_STR_LENGTH 1024

typedef struct json_object {
    char key[100];
    char value[500];
} json_object_t;

typedef struct json_obj_arr {
    json_object_t* objects;
    int count;
} json_obj_arr_t;

json_obj_arr_t json_obj_arr;
pthread_mutex_t lock;

void* parse_json(void* arg) {
    char* json_str = (char*)arg;
    char* token = strtok(json_str, "{");

    while(token != NULL) {
        if(strstr(token, "\"")) {
            json_object_t new_obj;
            char key[100];
            char value[500];
            sscanf(token, "\"%[^\"]\": \"%[^\"]\"", key, value);
            strcpy(new_obj.key, key);
            strcpy(new_obj.value, value);

            pthread_mutex_lock(&lock);
            json_obj_arr.objects = realloc(json_obj_arr.objects, (json_obj_arr.count + 1) * sizeof(json_object_t));
            json_obj_arr.objects[json_obj_arr.count++] = new_obj;
            pthread_mutex_unlock(&lock);
        }

        token = strtok(NULL, "{");
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    char json_str[MAX_JSON_STR_LENGTH];

    printf("Enter the json string: ");
    fgets(json_str, MAX_JSON_STR_LENGTH, stdin);

    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1, NULL, parse_json, (void*)json_str);
    pthread_create(&t2, NULL, parse_json, (void*)json_str);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Parsed JSON objects:\n");
    for(int i = 0; i < json_obj_arr.count; i++) {
        printf("%s : %s\n", json_obj_arr.objects[i].key, json_obj_arr.objects[i].value);
    }

    pthread_mutex_destroy(&lock);
    free(json_obj_arr.objects);
    return 0;
}