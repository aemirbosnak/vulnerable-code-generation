//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Peasant;

int main(void) {
    FILE *file = fopen("peasants.txt", "w");
    Peasant peasant;

    if (file == NULL) {
        printf("Lord, thy file could not be opened!\n");
        return 1;
    }

    printf("Enter the name of thy peasant: ");
    fgets(peasant.name, sizeof(peasant.name), stdin);
    peasant.name[strcspn(peasant.name, "\n")] = '\0';

    printf("Enter the age of thy peasant: ");
    scanf("%d", &peasant.age);

    printf("Enter the occupation of thy peasant: ");
    fgets(peasant.occupation, sizeof(peasant.occupation), stdin);
    peasant.occupation[strcspn(peasant.occupation, "\n")] = '\0';

    fprintf(file, "%s, %d, %s\n", peasant.name, peasant.age, peasant.occupation);

    fclose(file);
    printf("Thy peasant hath been added to the file!\n");

    // Reading data from file
    file = fopen("peasants.txt", "r");

    if (file == NULL) {
        printf("Lord, thy file could not be opened!\n");
        return 1;
    }

    while (fscanf(file, "%s, %d, %s", peasant.name, &peasant.age, peasant.occupation) != EOF) {
        printf("%s, %d, %s\n", peasant.name, peasant.age, peasant.occupation);
    }

    fclose(file);

    return 0;
}