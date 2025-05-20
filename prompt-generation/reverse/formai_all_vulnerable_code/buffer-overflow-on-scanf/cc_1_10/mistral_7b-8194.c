//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024

typedef struct {
    char name[MAX_LEN];
    int neon_level;
} NeonCitizen;

void neonize_name(char *name) {
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        if (name[i] >= 'a' && name[i] <= 'z') {
            name[i] += 3;
            if (name[i] > 'z') name[i] -= 26;
        }
    }
}

NeonCitizen *create_neon_citizen(char *name) {
    NeonCitizen *citizen = (NeonCitizen *) malloc(sizeof(NeonCitizen));
    strcpy(citizen->name, name);
    neonize_name(citizen->name);
    citizen->neon_level = rand() % 10 + 1;
    return citizen;
}

void delete_neon_citizen(NeonCitizen *citizen) {
    free(citizen);
}

void print_neon_citizen(NeonCitizen *citizen) {
    printf("%s [Neon Level: %d]\n", citizen->name, citizen->neon_level);
}

int main() {
    char input_name[MAX_LEN];
    int choice;

    NeonCitizen *citizen;

    printf("\nWelcome to the Neon City!\n");
    printf("----------------------------\n");

    while (1) {
        printf("\n1. Create a new Neon Citizen\n");
        printf("2. Delete a Neon Citizen\n");
        printf("3. Display all Neon Citizens\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", input_name);
                neonize_name(input_name);
                citizen = create_neon_citizen(input_name);
                printf("New Neon Citizen created!\n");
                print_neon_citizen(citizen);
                break;

            case 2:
                // To be implemented
                break;

            case 3:
                // To be implemented
                break;

            case 4:
                printf("Quitting Neon City...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}