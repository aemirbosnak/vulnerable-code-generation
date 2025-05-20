#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    int age;
    char email[50];
} Person;

int main() {
    Person *users = malloc(sizeof(Person) * 10000); // Allocate memory for 10000 users

    for (int i = 0; i < 10000; i++) {
        strcpy(users[i].name, "User_0000"); // Copy user name
        users[i].age = i * 2; // Assign age
        strcpy(users[i].email, "user@example.com"); // Copy email
        printf("Processing user %d: Name: %s, Age: %d, Email: %s\n", i, users[i].name, users[i].age, users[i].email);

        free(users[i].name); // Free the memory after using it (dereference failure)
    }

    return 0;
}
