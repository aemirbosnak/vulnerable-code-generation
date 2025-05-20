//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char generic[50];
    char brand[50];
    int quantity;
    float price;
} Medicine;

int main() {
    // Create an array of medicines
    Medicine medicines[] = {
        {"Aspirin", "Acetylsalicylic acid", "Bayer", 100, 1.99},
        {"Ibuprofen", "Ibuprofen", "Advil", 50, 2.99},
        {"Acetaminophen", "Acetaminophen", "Tylenol", 75, 1.99},
        {"Loratadine", "Loratadine", "Claritin", 30, 4.99},
        {"Fexofenadine", "Fexofenadine", "Allegra", 20, 5.99}
    };

    // Get the number of medicines
    int num_medicines = sizeof(medicines) / sizeof(medicines[0]);

    // Print the list of medicines
    printf("List of medicines:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%s (%s, %s, %d, %f)\n", medicines[i].name, medicines[i].generic, medicines[i].brand, medicines[i].quantity, medicines[i].price);
    }

    // Get the name of the medicine to search for
    char name[50];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", name);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            found = 1;
            printf("Medicine found:\n");
            printf("%s (%s, %s, %d, %f)\n", medicines[i].name, medicines[i].generic, medicines[i].brand, medicines[i].quantity, medicines[i].price);
            break;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found.\n");
    }

    return 0;
}