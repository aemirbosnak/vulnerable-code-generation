//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MEN 100

typedef struct {
    char name[50];
    int age;
} Man;

bool findLove(Man men[], int len, char *name, int *age) {
    int i;
    for (i = 0; i < len; i++) {
        if (strcmp(men[i].name, name) == 0) {
            *age = men[i].age;
            return true;
        }
    }
    return false;
}

int main() {
    Man men[MAX_MEN];
    int i, loveAge;
    char loveName[50];

    printf("Once upon a time, in a land of code and logic,\n");
    printf("Lived an extraordinary C programmer named C.\n");
    printf("With a heart full of love and a passion for C,\n");
    printf("She sought to find her true love in an array of men.\n");

    printf("Let us embark on this romantic quest together.\n");

    // Initialize the array of men
    for (i = 0; i < MAX_MEN; i++) {
        printf("Enter man %d's name: ", i + 1);
        scanf("%s", men[i].name);
        printf("Enter man %d's age: ", i + 1);
        scanf("%d", &men[i].age);
        printf("\n");
    }

    printf("Now, C, tell me the name of the one you love:\n");
    scanf("%s", loveName);

    if (findLove(men, MAX_MEN, loveName, &loveAge)) {
        printf("Ah, my dear C, your true love's age is %d!\n", loveAge);
    } else {
        printf("Alas, my dear C, it seems your true love is not in this array.\n");
    }

    printf("The search ends here, but the quest for love never does.\n");
    printf("May your code be elegant, and your heart be full of love.\n");

    return 0;
}