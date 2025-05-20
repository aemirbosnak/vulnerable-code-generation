//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_TEMP 100

int main()
{
    int choice;
    float temp;
    char name[20];
    FILE *fp;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, would you like to:\n", name);
    printf("1. Enter a temperature\n");
    printf("2. View temperature history\n");
    printf("3. Quit\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter temperature (0-100): ");
            scanf("%f", &temp);
            if(temp >= 0 && temp <= MAX_TEMP)
            {
                fp = fopen("temp_history.txt", "a");
                fprintf(fp, "%s entered a temperature of %.2f degrees.\n", name, temp);
                fclose(fp);
                printf("\nTemperature recorded successfully!\n");
            }
            else
            {
                printf("\nInvalid temperature range. Please try again.\n");
            }
            break;

        case 2:
            fp = fopen("temp_history.txt", "r");
            if(fp!= NULL)
            {
                printf("\nTemperature history:\n");
                while(fscanf(fp, "%s entered a temperature of %.2f degrees.\n", name, &temp)!= EOF)
                {
                    printf("%s: %.2f degrees\n", name, temp);
                }
                fclose(fp);
            }
            else
            {
                printf("\nNo temperature history found.\n");
            }
            break;

        case 3:
            printf("\n%s, thank you for using the Temperature Monitor!\n", name);
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }

    return 0;
}