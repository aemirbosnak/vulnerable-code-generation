//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 100
#define MAX_THEORY_LENGTH 50

typedef struct {
    char name[MAX_THEORY_LENGTH];
    char description[MAX_THEORY_LENGTH];
} theory_t;

theory_t theories[MAX_THEORIES];
int num_theories = 0;


void generate_theory(char* name, char* description) {
    int i;
    for(i = 0; i < num_theories; i++) {
        if(strcmp(theories[i].name, name) == 0) {
            printf("Error: Duplicate theory name '%s'\n", name);
            return;
        }
    }

    strcpy(theories[num_theories].name, name);
    strcpy(theories[num_theories].description, description);
    num_theories++;
}

void print_theory(int index) {
    if(index < 0 || index >= num_theories) {
        printf("Error: Invalid theory index\n");
        return;
    }

    printf("Theory #%d:\n", index+1);
    printf("Name: %s\n", theories[index].name);
    printf("Description: %s\n", theories[index].description);
}

void print_all_theories() {
    int i;
    for(i = 0; i < num_theories; i++) {
        print_theory(i);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Random Conspiracy Theory Generator\n");
        printf("1. Generate a new theory\n");
        printf("2. Print all theories\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter theory name: ");
                char name[MAX_THEORY_LENGTH];
                scanf("%s", name);

                printf("Enter theory description: ");
                char description[MAX_THEORY_LENGTH];
                scanf("%s", description);

                generate_theory(name, description);
                break;

            case 2:
                print_all_theories();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}