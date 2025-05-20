//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char gender;
} Person;

int main(int argc, char *argv[]) {
    FILE *file1, *file2;
    Person *persons1, *persons2, temp;
    int n1, n2, i, j;

    // Romeo's file
    file1 = fopen("romeo.txt", "r");
    fscanf(file1, "%d", &n1);
    persons1 = (Person *) malloc(n1 * sizeof(Person));
    for (i = 0; i < n1; i++) {
        fscanf(file1, "%s %d %c", persons1[i].name, &persons1[i].age, &persons1[i].gender);
    }
    fclose(file1);

    // Juliet's file
    file2 = fopen("juliet.txt", "r");
    fscanf(file2, "%d", &n2);
    persons2 = (Person *) malloc(n2 * sizeof(Person));
    for (i = 0; i < n2; i++) {
        fscanf(file2, "%s %d %c", persons2[i].name, &persons2[i].age, &persons2[i].gender);
    }
    fclose(file2);

    // Comparing Romeo and Juliet's love interests
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (strcmp(persons1[i].name, persons2[j].name) == 0) {
                temp = persons1[i];
                persons1[i] = persons2[j];
                persons2[j] = temp;
                break;
            }
        }
    }

    // Printing results
    printf("Romeo's matches:\n");
    for (i = 0; i < n1; i++) {
        printf("%s (%d years old, %c)\n", persons1[i].name, persons1[i].age, persons1[i].gender);
    }

    printf("\nJuliet's matches:\n");
    for (i = 0; i < n2; i++) {
        printf("%s (%d years old, %c)\n", persons2[i].name, persons2[i].age, persons2[i].gender);
    }

    free(persons1);
    free(persons2);

    return 0;
}