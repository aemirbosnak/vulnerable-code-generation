//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char stock_name[20];
    printf("Enter stock name: ");
    scanf("%s", stock_name);

    FILE *fp = fopen(stock_name, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    int i = 0;
    while (fgets(line, 1024, fp) != NULL)
    {
        char price[10];
        char change[10];
        int index = 0;
        for (int j = 0; line[j] != '\0'; j++)
        {
            if (line[j] >= '0' && line[j] <= '9')
            {
                price[index] = line[j];
                index++;
            }
            else if (line[j] == '+')
            {
                change[index] = line[j];
                index++;
            }
        }

        int p = atoi(price);
        int c = atoi(change);
        printf("Stock name: %s\n", stock_name);
        printf("Price: %d\n", p);
        printf("Change: %d\n", c);
        printf("------------------------\n");
        i++;
    }

    fclose(fp);
    return 0;
}