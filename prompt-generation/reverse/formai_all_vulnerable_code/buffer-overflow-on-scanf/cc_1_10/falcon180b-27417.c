//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
//Function to check if a given element is present in the periodic table or not
int check(char *element)
{
    FILE *fp;
    char line[100];
    char *ptr;
    fp = fopen("periodic_table.txt", "r");
    while (fgets(line, 100, fp)!= NULL) {
        if (strcasecmp(line, element) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
//Function to display the periodic table
void display()
{
    FILE *fp;
    char line[100];
    fp = fopen("periodic_table.txt", "r");
    while (fgets(line, 100, fp)!= NULL) {
        printf("%s", line);
    }
    fclose(fp);
}
int main()
{
    int choice, flag = 0;
    char element[20];
    printf("Periodic Table Quiz\n");
    printf("1. Display Periodic Table\n2. Quiz\n3. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            display();
            break;
        case 2:
            printf("Enter the name of the element: ");
            scanf("%s", element);
            if (check(element)) {
                printf("Element found in the periodic table!\n");
            } else {
                printf("Element not found in the periodic table.\n");
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}