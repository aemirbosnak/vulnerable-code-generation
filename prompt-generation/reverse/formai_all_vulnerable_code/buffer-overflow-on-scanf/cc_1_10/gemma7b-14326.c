//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct Item {
    char name[20];
    char description[100];
    int category;
} Item;

Item items[] = {
    {"Silver Teapot", "A gleaming teapot, perfect for a cuppa.", 1},
    {"Antique Clock", "A vintage clock with a charming patina.", 3},
    {"Leather Briefcase", "A stylish briefcase, ideal for carrying documents.", 2},
    {"Vintage Sword", "A historical sword, hung on the wall.", 3},
    {"Antique Mirror", "A framed mirror with a vintage design.", 3}
};

int main() {
    char query[20];
    int i, category;

    printf("Welcome, dear Watson, to the grand mystery of the C Image Classification System.\n");

    // Get the query from the user
    printf("What item are you looking for? ");
    scanf("%s", query);

    // Search for the item
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(items[i].name, query) == 0) {
            // Print the item's category
            category = items[i].category;
            printf("The item's category is: ");
            switch (category) {
                case 1:
                    printf("Silverware.\n");
                    break;
                case 2:
                    printf("Leather goods.\n");
                    break;
                case 3:
                    printf("Antique items.\n");
                    break;
            }
            break;
        }
    }

    // If the item was not found, print an error message
    if (i == MAX_WORDS) {
        printf("Sorry, the item was not found.\n");
    }

    return 0;
}