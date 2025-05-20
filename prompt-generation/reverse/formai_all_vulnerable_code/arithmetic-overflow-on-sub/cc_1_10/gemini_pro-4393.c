//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: excited
// Welcome to the most exciting Medical Store Management System Program! Get ready for a wild ride!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We'll keep track of our awesome medicines and their superpowers!
typedef struct Medicine {
    char name[100];
    char description[500];
    int quantity;
    float price;
} Medicine;

// Let's keep a list of these amazing medicines!
Medicine medicines[100];

// Time to add some cool features to our system!
void addMedicine() {
    printf("Yay! Let's add a new superhero medicine!\n");
    Medicine newMedicine;
    printf("What's the name of this medical superhero?\n");
    scanf("%s", newMedicine.name);
    printf("Describe its superpowers (500 characters max):\n");
    scanf(" %[^\n]%*c", newMedicine.description); // Let's be flexible with descriptions!
    printf("How many do we have in stock?\n");
    scanf("%d", &newMedicine.quantity);
    printf("What's its price (in currency you love)?\n");
    scanf("%f", &newMedicine.price);
    // Let's add it to our list!
    for (int i = 0; i < 100; i++) {
        if (medicines[i].name[0] == '\0') {
            medicines[i] = newMedicine;
            printf("Woohoo! Our new medical superhero has arrived!\n");
            return;
        }
    }
    printf("Oops, our medicine cabinet is full! Try again later.\n");
}

// Customers need their medicines! Let's see what we have.
void viewMedicines() {
    printf("Ta-da! Here's our list of medical superheroes:\n");
    for (int i = 0; i < 100; i++) {
        if (medicines[i].name[0] != '\0') {
            printf("Name: %s\n", medicines[i].name);
            printf("Superpowers: %s\n", medicines[i].description);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n\n", medicines[i].price);
        }
    }
}

// Someone's feeling better! Let's update our stock.
void sellMedicine() {
    char name[100];
    int quantity;
    printf("Which medical superhero do you need? (Name):\n");
    scanf("%s", name);
    printf("How many do you need to conquer your illness?\n");
    scanf("%d", &quantity);
    for (int i = 0; i < 100; i++) {
        if (!strcmp(medicines[i].name, name)) {
            if (medicines[i].quantity >= quantity) {
                medicines[i].quantity -= quantity;
                printf("Here you go! %d %s to save the day!\n", quantity, name);
                return;
            } else {
                printf("Sorry, we don't have that many. Check back later!\n");
                return;
            }
        }
    }
    printf("Oops! We don't have that medicine. Try something else!\n");
}

// Time to restock our medical superhero squad!
void restockMedicine() {
    char name[100];
    int quantity;
    printf("Which medical superhero needs reinforcements? (Name):\n");
    scanf("%s", name);
    printf("How many are joining the battle against illness?\n");
    scanf("%d", &quantity);
    for (int i = 0; i < 100; i++) {
        if (!strcmp(medicines[i].name, name)) {
            medicines[i].quantity += quantity;
            printf("Reinforcements have arrived! %d more %s ready to fight!\n", quantity, name);
            return;
        }
    }
    printf("Oops! That medicine isn't in our system. Try again!\n");
}

// The main event! Let's start our medical superhero management system!
int main() {
    printf("Welcome to the most EPIC Medical Store Management System!\n");
    int choice;
    do {
        printf("\nWhat superpower do you need today?\n");
        printf("1. Add a New Medical Superhero\n2. View Our Medical Superheroes\n3. Sell a Medical Superhero\n4. Restock Medical Superheroes\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                sellMedicine();
                break;
            case 4:
                restockMedicine();
                break;
            case 5:
                printf("Thanks for managing your medical superheroes with us! Stay healthy!\n");
                break;
            default:
                printf("Oops! Invalid superpower. Try again!\n");
        }
    } while (choice != 5);
    return 0;
}