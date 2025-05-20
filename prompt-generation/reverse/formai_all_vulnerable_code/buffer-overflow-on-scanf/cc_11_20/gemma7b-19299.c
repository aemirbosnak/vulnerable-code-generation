//Gemma-7B DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    system("clear");
    printf("Welcome to the C System Administration Terminal!");
    printf("\nPlease select an option:");
    printf("\n1. View System Inventory");
    printf("\n2. Add New Hardware");
    printf("\n3. Remove Hardware");
    printf("\n4. Update Hardware Status");
    printf("\n5. Exit");

    int choice = 0;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            system("cat inventory.txt");
            break;
        case 2:
            printf("Enter the name of the new hardware:");
            char name[256];
            scanf("%s", name);

            printf("Enter the quantity of the new hardware:");
            int quantity = 0;
            scanf("%d", &quantity);

            FILE *fp = fopen("inventory.txt", "a");
            fprintf(fp, "%s, %d\n", name, quantity);
            fclose(fp);

            printf("New hardware added successfully!");
            break;
        case 3:
            printf("Enter the name of the hardware to remove:");
            char removeName[256];
            scanf("%s", removeName);

            FILE *fp1 = fopen("inventory.txt", "r");
            FILE *fp2 = fopen("temp.txt", "w");

            char line[256];
            int found = 0;
            while (fgets(line, 256, fp1) != NULL)
            {
                if (strcmp(line, removeName) == 0)
                {
                    found = 1;
                }
                else
                {
                    fprintf(fp2, line);
                }
            }

            fclose(fp1);
            fclose(fp2);

            if (found)
            {
                printf("Hardware removed successfully!");
            }
            else
            {
                printf("Error removing hardware!");
            }
            break;
        case 4:
            printf("Enter the name of the hardware to update:");
            char updateName[256];
            scanf("%s", updateName);

            printf("Enter the new quantity of the hardware:");
            int newQuantity = 0;
            scanf("%d", &newQuantity);

            FILE *fp3 = fopen("inventory.txt", "r");
            FILE *fp4 = fopen("temp.txt", "w");

            char line1[256];
            int found1 = 0;
            while (fgets(line1, 256, fp3) != NULL)
            {
                if (strcmp(line1, updateName) == 0)
                {
                    found1 = 1;
                    fprintf(fp4, "%s, %d\n", updateName, newQuantity);
                }
                else
                {
                    fprintf(fp4, line1);
                }
            }

            fclose(fp3);
            fclose(fp4);

            if (found1)
            {
                printf("Hardware status updated successfully!");
            }
            else
            {
                printf("Error updating hardware status!");
            }
            break;
        case 5:
            printf("Thank you for using the C System Administration Terminal!");
            break;
        default:
            printf("Invalid option!");
            break;
    }

    return 0;
}