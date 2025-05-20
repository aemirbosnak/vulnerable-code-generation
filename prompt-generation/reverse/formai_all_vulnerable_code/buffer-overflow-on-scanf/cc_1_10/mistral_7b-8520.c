//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

int main() {
    Person Romeo, Juliet;
    char fatherName[MAX_NAME_LENGTH];
    char motherName[MAX_NAME_LENGTH];

    printf("Enter Romeo's name: ");
    scanf("%s", Romeo.name);
    printf("Enter Romeo's age: ");
    scanf("%d", &Romeo.age);

    printf("Enter Juliet's name: ");
    scanf("%s", Juliet.name);
    printf("Enter Juliet's age: ");
    scanf("%d", &Juliet.age);

    printf("Enter Romeo's father's name: ");
    scanf("%s", fatherName);
    strcpy(Romeo.name, fatherName);

    printf("Enter Romeo's mother's name: ");
    scanf("%s", motherName);
    strcpy(Romeo.name + strlen(fatherName) + 1, motherName);

    printf("Enter Juliet's father's name: ");
    scanf("%s", fatherName);
    strcpy(Juliet.name, fatherName);

    printf("Enter Juliet's mother's name: ");
    scanf("%s", motherName);
    strcpy(Juliet.name + strlen(fatherName) + 1, motherName);

    if (strcmp(Romeo.name, Juliet.name) == 0) {
        printf("Error: Romeo and Juliet are the same person!\n");
        return 1;
    }

    printf("Romeo's full name is %s\n", Romeo.name);
    printf("Juliet's full name is %s\n", Juliet.name);

    if (Romeo.age + Juliet.age < 18) {
        printf("Error: Romeo and Juliet are too young to fall in love!\n");
        return 1;
    }

    printf("Romeo and Juliet are in love!\n");

    return 0;
}