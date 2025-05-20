//FormAI DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Funny Querying Program!\n");
    printf("*************************************\n");

    // create a database of comedians
    struct comedian {
        char name[20];
        char style[15];
        int age;
        int net_worth;
    };

    struct comedian comedians[3];

    strcpy(comedians[0].name, "Dave Chappelle");
    strcpy(comedians[0].style, "Storytelling");
    comedians[0].age = 48;
    comedians[0].net_worth = 50;

    strcpy(comedians[1].name, "Kevin Hart");
    strcpy(comedians[1].style, "Observational");
    comedians[1].age = 42;
    comedians[1].net_worth = 200;

    strcpy(comedians[2].name, "Amy Schumer");
    strcpy(comedians[2].style, "Controversial");
    comedians[2].age = 39;
    comedians[2].net_worth = 16;
    
    // let's find the oldest comedian
    int oldest_index = 0;
    for (int i = 1; i < 3; i++) {
        if (comedians[i].age > comedians[oldest_index].age) {
            oldest_index = i;
        }
    }
    printf("The oldest comedian is %s\n", comedians[oldest_index].name);

    // now let's find the richest comedian
    int richest_index = 0;
    for (int i = 1; i < 3; i++) {
        if (comedians[i].net_worth > comedians[richest_index].net_worth) {
            richest_index = i;
        }
    }
    printf("The richest comedian is %s\n", comedians[richest_index].name);

    // finally, let's search for a comedian by their style
    char search_style[15];
    printf("Enter a comedy style to search for: ");
    scanf("%s", search_style);

    int style_found = 0;
    for (int i = 0; i < 3; i++) {
        if (strcmp(comedians[i].style, search_style) == 0) {
            printf("%s is a %s comedian\n", comedians[i].name, comedians[i].style);
            style_found = 1;
        }
    }

    if (style_found == 0) {
        printf("No comedians found with the style %s\n", search_style);
    }

    return 0;
}