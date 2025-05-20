//Falcon-180B DATASET v1.0 Category: Memory management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 1000
#define CHAR_SIZE sizeof(char)

typedef struct {
    char name[50];
    int age;
} knight_t;

void create_knight(knight_t* knight, char* name, int age) {
    strncpy(knight->name, name, 49);
    knight->age = age;
}

void print_knight(knight_t* knight) {
    printf("Name: %s\n", knight->name);
    printf("Age: %d\n", knight->age);
}

void print_array(knight_t* array, int size) {
    for(int i = 0; i < size; i++) {
        print_knight(&array[i]);
    }
}

int main() {
    knight_t* array = (knight_t*)malloc(MAX_ARRAY_SIZE * sizeof(knight_t));
    int size = 0;

    while(size < MAX_ARRAY_SIZE) {
        char name[50];
        int age;

        printf("Enter the name of the knight: ");
        scanf("%s", name);

        printf("Enter the age of the knight: ");
        scanf("%d", &age);

        create_knight(&array[size], name, age);
        size++;
    }

    print_array(array, size);

    free(array);

    return 0;
}