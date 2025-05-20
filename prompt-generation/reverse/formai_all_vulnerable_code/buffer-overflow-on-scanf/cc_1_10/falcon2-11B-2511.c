//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char gender[10];
    char address[100];
} voter_t;

int main() {
    voter_t voter1 = {"John Doe", 25, "Male", "123 Main St."};
    voter_t voter2 = {"Jane Smith", 30, "Female", "456 Oak St."};
    voter_t voter3 = {"Mike Johnson", 22, "Male", "789 Maple St."};

    int choice = 0;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your name: ");
    fgets(voter1.name, sizeof(voter1.name), stdin);
    printf("Please enter your age: ");
    scanf("%d", &voter1.age);
    printf("Please enter your gender: ");
    fgets(voter1.gender, sizeof(voter1.gender), stdin);
    printf("Please enter your address: ");
    fgets(voter1.address, sizeof(voter1.address), stdin);

    printf("\nPlease enter the name of the next voter: ");
    fgets(voter2.name, sizeof(voter2.name), stdin);
    printf("Please enter the age of the next voter: ");
    scanf("%d", &voter2.age);
    printf("Please enter the gender of the next voter: ");
    fgets(voter2.gender, sizeof(voter2.gender), stdin);
    printf("Please enter the address of the next voter: ");
    fgets(voter2.address, sizeof(voter2.address), stdin);

    printf("\nPlease enter the name of the next voter: ");
    fgets(voter3.name, sizeof(voter3.name), stdin);
    printf("Please enter the age of the next voter: ");
    scanf("%d", &voter3.age);
    printf("Please enter the gender of the next voter: ");
    fgets(voter3.gender, sizeof(voter3.gender), stdin);
    printf("Please enter the address of the next voter: ");
    fgets(voter3.address, sizeof(voter3.address), stdin);

    printf("\nPlease enter your choice (1, 2, or 3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("The first voter is %s, %d years old, %s, and lives at %s.\n", voter1.name, voter1.age, voter1.gender, voter1.address);
        printf("The second voter is %s, %d years old, %s, and lives at %s.\n", voter2.name, voter2.age, voter2.gender, voter2.address);
        printf("The third voter is %s, %d years old, %s, and lives at %s.\n", voter3.name, voter3.age, voter3.gender, voter3.address);
    } else if (choice == 2) {
        printf("The first voter is %s, %d years old, %s, and lives at %s.\n", voter1.name, voter1.age, voter1.gender, voter1.address);
        printf("The second voter is %s, %d years old, %s, and lives at %s.\n", voter2.name, voter2.age, voter2.gender, voter2.address);
        printf("The third voter is %s, %d years old, %s, and lives at %s.\n", voter3.name, voter3.age, voter3.gender, voter3.address);
    } else if (choice == 3) {
        printf("The first voter is %s, %d years old, %s, and lives at %s.\n", voter1.name, voter1.age, voter1.gender, voter1.address);
        printf("The second voter is %s, %d years old, %s, and lives at %s.\n", voter2.name, voter2.age, voter2.gender, voter2.address);
        printf("The third voter is %s, %d years old, %s, and lives at %s.\n", voter3.name, voter3.age, voter3.gender, voter3.address);
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}