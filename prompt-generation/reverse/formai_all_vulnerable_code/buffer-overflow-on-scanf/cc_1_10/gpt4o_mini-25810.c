//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <string.h>

#define MAX_PARTNERS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int affection_score;
} Partner;

void initialize_partners(Partner partners[]) {
    strcpy(partners[0].name, "Isabella");
    partners[0].affection_score = 80;

    strcpy(partners[1].name, "Julian");
    partners[1].affection_score = 65;

    strcpy(partners[2].name, "Clara");
    partners[2].affection_score = 90;

    strcpy(partners[3].name, "Lorenzo");
    partners[3].affection_score = 55;

    strcpy(partners[4].name, "Sophia");
    partners[4].affection_score = 70;

    strcpy(partners[5].name, "Ethan");
    partners[5].affection_score = 75;

    strcpy(partners[6].name, "Amelie");
    partners[6].affection_score = 85;

    strcpy(partners[7].name, "Marcus");
    partners[7].affection_score = 60;

    strcpy(partners[8].name, "Rosa");
    partners[8].affection_score = 95;

    strcpy(partners[9].name, "Victor");
    partners[9].affection_score = 50;
}

int search_for_love(Partner partners[], int count, const char *desired_name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(partners[i].name, desired_name) == 0) {
            return i; // Return the index of the found partner
        }
    }
    return -1; // Return -1 if not found
}

void reveal_love(Partner partners[], int index) {
    printf("Oh, sweet love found! %s has an affection score of %d.\n", 
           partners[index].name, partners[index].affection_score);
    printf("Let's cherish this bond forever!\n");
}

int main() {
    Partner partners[MAX_PARTNERS];
    initialize_partners(partners);

    char desired_name[NAME_LENGTH];
    printf("My heart whispers a name, who do I seek? (Type a partner's name): ");
    scanf("%s", desired_name);

    int index = search_for_love(partners, MAX_PARTNERS, desired_name);

    if (index != -1) {
        reveal_love(partners, index);
    } else {
        printf("Alas, my heart cannot find the one I seek.\n");
        printf("Perhaps fate shall guide us to cross paths another day!\n");
    }

    printf("Let the search for love continue...\n");
    return 0;
}