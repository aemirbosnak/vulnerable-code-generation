//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_UNITS 20

typedef struct {
    char name[40];
    double factor;
    int index;
} Unit;

typedef struct {
    char name[40];
    int numUnits;
    Unit units[MAX_UNITS];
} Category;

int main() {
    Category categories[MAX_CATEGORIES];
    int numCategories = 0;
    int choice;

    do {
        printf("Unit Converter\n");
        printf("1. Add category\n");
        printf("2. Remove category\n");
        printf("3. Convert units\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if(numCategories >= MAX_CATEGORIES) {
                    printf("Maximum number of categories reached. ");
                } else {
                    printf("Enter category name: ");
                    scanf("%s", categories[numCategories].name);
                    numCategories++;
                }
                break;
            }
            case 2: {
                printf("Enter category name to remove: ");
                scanf("%s", categories[numCategories-1].name);
                numCategories--;
                break;
            }
            case 3: {
                printf("Enter category name: ");
                scanf("%s", categories[numCategories-1].name);
                printf("Enter unit name: ");
                scanf("%s", categories[numCategories-1].units[categories[numCategories-1].numUnits-1].name);
                printf("Enter conversion factor: ");
                scanf("%lf", &categories[numCategories-1].units[categories[numCategories-1].numUnits-1].factor);
                categories[numCategories-1].numUnits++;
                break;
            }
            case 4: {
                printf("Exiting... ");
                break;
            }
            default: {
                printf("Invalid choice. ");
            }
        }

    } while(choice!= 4);

    return 0;
}