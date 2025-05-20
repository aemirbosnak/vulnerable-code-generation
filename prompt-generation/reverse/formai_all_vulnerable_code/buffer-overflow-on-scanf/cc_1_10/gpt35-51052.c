//FormAI DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct for holding romantic partner details
struct Partner {
    char name[20];
    int age;
    char interests[50];
};

// Function for comparing partner ages
int compareAge(const void* a, const void* b) {
    struct Partner* partnerA = (struct Partner*)a;
    struct Partner* partnerB = (struct Partner*)b;
    return (partnerA->age - partnerB->age);
}

// Function for comparing partner interests
int compareInterests(const void* a, const void* b) {
    struct Partner* partnerA = (struct Partner*)a;
    struct Partner* partnerB = (struct Partner*)b;
    return (strcmp(partnerA->interests, partnerB->interests));
}

int main() {

    struct Partner partners[5]; // Declare array of Partners
    
    printf("Welcome to my matchmaking program!\n");
    printf("Please enter the details of 5 potential romantic partners:\n");

    // Get details of all partners 
    for (int i = 0; i < 5; i++) {
        printf("\nPartner %d:\n", i+1);
        printf("Name: ");
        scanf("%s", partners[i].name);
        printf("Age: ");
        scanf("%d", &partners[i].age);
        printf("Interests: ");
        scanf("%s", partners[i].interests);
    }

    // Sort partners by age using quicksort
    qsort(partners, 5, sizeof(struct Partner), compareAge);

    printf("\nSorted by age:\n");

    // Print partners sorted by age
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d, Interests: %s\n", partners[i].name, partners[i].age, partners[i].interests);
    }

    // Sort partners by interests using quicksort
    qsort(partners, 5, sizeof(struct Partner), compareInterests);

    printf("\nSorted by interests:\n");

    // Print partners sorted by interests
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d, Interests: %s\n", partners[i].name, partners[i].age, partners[i].interests);
    }

    printf("\nThank you for using my matchmaking program!\n");

  return 0;
}