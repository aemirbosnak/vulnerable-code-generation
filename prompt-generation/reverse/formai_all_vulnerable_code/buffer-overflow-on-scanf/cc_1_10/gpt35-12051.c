//FormAI DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Welcome to the Mind-Bending C Database Querying program! */

/* Our database holds information about the fortunes of great minds */
typedef struct {
    char name[50];
    char fortune[200];
} MindFortune;

/* Here's our main function */
int main() {

    /* Let's first read in the number of great minds we have fortunes for */
    int num_minds;
    printf("Enter the number of great minds whose fortunes we have: ");
    scanf("%d", &num_minds);

    /* Now let's dynamically allocate an array of type MindFortune to hold the fortunes for each great mind */
    MindFortune *fortune_array = (MindFortune*) malloc(num_minds * sizeof(MindFortune));

    /* Let's read in each great mind's name and fortune */
    for (int i=0; i<num_minds; i++) {
        printf("\nEnter the name of the great mind %d: ", i+1);
        scanf("%s", fortune_array[i].name);

        printf("Enter %s's fortune: ", fortune_array[i].name);
        scanf(" %[^\n]", fortune_array[i].fortune); /* we use "%[^\n]" to read the entire fortune until the newline character */
    }

    /* Now let's query the database for a particular great mind's fortune */
    char query_name[50];
    printf("\nEnter the name of the great mind you want the fortune for: ");
    scanf("%s", query_name);

    int query_index = -1;
    for (int i=0; i<num_minds; i++) {
        if (strcmp(fortune_array[i].name, query_name) == 0) {
            query_index = i;
            break;
        }
    }

    if (query_index == -1) {
        printf("Sorry, we couldn't find a fortune for %s.\n", query_name);
    } else {
        printf("%s's fortune: %s\n", fortune_array[query_index].name, fortune_array[query_index].fortune);
    }

    /* Let's free up the memory we allocated */
    free(fortune_array);

    return 0;
}