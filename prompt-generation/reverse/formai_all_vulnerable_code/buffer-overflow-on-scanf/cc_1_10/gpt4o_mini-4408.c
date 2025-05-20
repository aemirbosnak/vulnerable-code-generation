//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_CHARACTERS 20

// The tale of searching Romeo's heart among the names of the Capulet family
void declareLove(const char *name) {
    printf("O, fairest %s, my heart doth yearn for thee!\n", name);
}

void searchForLove(char names[MAX_CHARACTERS][20], int count, const char *beloved) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], beloved) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        declareLove(beloved);
    } else {
        printf("Alas! %s is not among the Capulets' names.\n", beloved);
    }
}

void actOne() {
    // The familial names of the Capulet clan
    char capuletNames[MAX_CHARACTERS][20] = {
        "Juliet",
        "Tybalt",
        "Paris",
        "Lord Capulet",
        "Lady Capulet",
        "Benvolio",
        "Nurse",
        "Sampson",
        "Gregory",
        "Mercutio",
        "Apothecary",
        "Prince Escalus",
        "Friar Laurence",
        "Balthasar",
        "Rosaline",
        "Petruchio",
        "Abram",
        "Peter",
        "Capulet",
        "Servant"
    };

    int count = 20; // The illustrious number of Capulet characters
    char romeoMessage[20];

    printf("Enter the beloved name that Romeo seeks: ");
    scanf("%s", romeoMessage);

    searchForLove(capuletNames, count, romeoMessage);
}

void actTwo() {
    printf("\nIn the moonlit garden, Romeo's heart beats...\n");
    printf("Shall we weave more names or dare venture further?\n");
}

void actThree() {
    int wishesToContinue;
    printf("\nWould you wish to search again?\n1. Yes\n2. No\nYour choice: ");
    scanf("%d", &wishesToContinue);
    
    if (wishesToContinue == 1) {
        actOne(); // Should the quest continue, reenter
    } else {
        printf("The curtain falls, sweet love shall rest till the morrow...\n");
    }
}

int main() {
    printf("A search for love in fair Verona begins...\n");

    actOne();  // Initiate the romantic quest
    actTwo();  // The intermission, a moment of reflection
    actThree(); // Conclude the saga or continue anew
    
    return 0;
}