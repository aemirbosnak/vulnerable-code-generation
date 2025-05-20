//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    char type[NAME_LENGTH]; // Type of pet (e.g., Dog, Cat)
    int isAdopted; // Flag for adoption status
} Pet;

Pet petDatabase[MAX_PETS];
int petCount = 0;

// Function prototypes
void addPet(char* name, int age, char* type);
void listPets();
void adoptPet(char* name);
void showHelp();

int main() {
    int choice;
    char name[NAME_LENGTH];
    int age;
    char type[NAME_LENGTH];

    printf("Welcome to the Silly Pet Adoption Database!\n");
    showHelp();

    while (1) {
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // Eat the newline character 

        switch (choice) {
            case 1:
                printf("Enter the pet name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter the pet age (in dog years, we won't judge): ");
                scanf("%d", &age);
                getchar(); // Eat the newline character

                printf("Enter the pet type (e.g., Dog, Cat, Unicorn): ");
                fgets(type, NAME_LENGTH, stdin);
                type[strcspn(type, "\n")] = 0; // Remove newline

                addPet(name, age, type);
                break;
            case 2:
                listPets();
                break;
            case 3:
                printf("Enter the name of the pet to adopt: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                adoptPet(name);
                break;
            case 4:
                showHelp();
                break;
            default:
                printf("Whoa there! That option doesn’t exist—try again!\n");
        }
    }

    return 0;
}

void addPet(char* name, int age, char* type) {
    if (petCount < MAX_PETS) {
        strcpy(petDatabase[petCount].name, name);
        petDatabase[petCount].age = age;
        strcpy(petDatabase[petCount].type, type);
        petDatabase[petCount].isAdopted = 0; // Not adopted yet
        petCount++;
        printf("Woof! %s the %s has been added to the database!\n", name, type);
    } else {
        printf("Oops! The database is full—no more furry friends!\n");
    }
}

void listPets() {
    printf("\n--- List of Pets ---\n");
    for (int i = 0; i < petCount; i++) {
        printf("%s, a %d-year-old %s. ", petDatabase[i].name, petDatabase[i].age, petDatabase[i].type);
        if (petDatabase[i].isAdopted) {
            printf("😻 (This pet is already adopted!)\n");
        } else {
            printf("🐾 (Available for adoption!)\n");
        }
    }
    printf("----------------------\n");
}

void adoptPet(char* name) {
    for (int i = 0; i < petCount; i++) {
        if (strcmp(petDatabase[i].name, name) == 0 && !petDatabase[i].isAdopted) {
            petDatabase[i].isAdopted = 1;
            printf("Yay! You have adopted %s! 🎉 Give it a hug!\n", name);
            return;
        } else if (strcmp(petDatabase[i].name, name) == 0) {
            printf("Sorry, %s has already been adopted! No take-backs!\n", name);
            return;
        }
    }
    printf("Hmm... I couldn't find a pet named %s! Are you trying to adopt a ghost?\n", name);
}

void showHelp() {
    printf("Commands:\n");
    printf("1: Add a pet to the database\n");
    printf("2: List all pets\n");
    printf("3: Adopt a pet\n");
    printf("4: Show this help message again\n");
    printf("Don't worry, we won’t bite! 🐶\n");
}