//FormAI DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
} Person;

void display_menu() {
    printf("Welcome to the royal data recovery tool!\n");
    printf("Select an option from the menu:\n");
    printf("1. Recover data from the knight's logs\n");
    printf("2. Recover data from the king's decree\n");
    printf("3. Recover data from the queen's memoirs\n");
    printf("4. Exit\n");
}

void display_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Occupation: %s\n", person->occupation);
}

void recover_data(FILE *file) {
    Person person;
    while (fread(&person, sizeof(Person), 1, file)) {
        display_person(&person);
    }
}

int main(void) {
    printf("Welcome to the medieval data recovery tool!\n");

    int option = 0;
    while (option != 4) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1: {
                FILE *knight_file = fopen("knight_logs.bin", "rb");
                if (knight_file) {
                    printf("Recovering data from knight's logs...\n");
                    recover_data(knight_file);
                    fclose(knight_file);
                } else {
                    printf("The knight's logs were not found.\n");
                }
                break;
            }
            case 2: {
                FILE *king_file = fopen("king_decree.bin", "rb");
                if (king_file) {
                    printf("Recovering data from king's decree...\n");
                    recover_data(king_file);
                    fclose(king_file);
                } else {
                    printf("The king's decree was not found.\n");
                }
                break;
            }
            case 3: {
                FILE *queen_file = fopen("queen_memoirs.bin", "rb");
                if (queen_file) {
                    printf("Recovering data from queen's memoirs...\n");
                    recover_data(queen_file);
                    fclose(queen_file);
                } else {
                    printf("The queen's memoirs were not found.\n");
                }
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid option.\n");
                break;
            }
        }
    }

    return 0;
}