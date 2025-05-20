//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUM_INPUTS 5

typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
} Person;

void read_person(Person *person, char *error_message) {
    printf("Enter name: ");
    fgets(person->name, MAX_STRING_LENGTH, stdin);
    if (strlen(person->name) >= MAX_STRING_LENGTH) {
        strcpy(error_message, "Name too long!");
        free(person);
        return;
    }

    printf("Enter age: ");
    if (scanf("%d", &person->age) != 1) {
        char temp_error_message[MAX_STRING_LENGTH];
        switch (errno) {
            case ERANGE:
                strcpy(error_message, "Age too large!");
                break;
            case EINVAL:
                strcpy(error_message, "Invalid age input!");
                break;
            default:
                strcpy(temp_error_message, "Unknown error occurred!");
                strcpy(error_message, temp_error_message);
                break;
        }
        free(person);
        return;
    }
}

int main() {
    Person people[MAX_NUM_INPUTS];
    char error_message[MAX_STRING_LENGTH];
    int i;

    for (i = 0; i < MAX_NUM_INPUTS; i++) {
        printf("Input person %d data:\n", i + 1);
        read_person(&people[i], error_message);
        if (strlen(error_message) > 0) {
            printf("%s\n", error_message);
            continue;
        }
        printf("Person %d data input successfully!\n", i + 1);
    }

    printf("All persons data input completed.\n");
    return 0;
}