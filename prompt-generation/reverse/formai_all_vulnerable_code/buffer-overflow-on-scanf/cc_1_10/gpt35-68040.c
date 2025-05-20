//FormAI DATASET v1.0 Category: Data mining ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

struct Medals{
    char country[50];
    int gold;
    int silver;
    int bronze;
};

struct Medals *createMedalTable(int n)
{
    struct Medals *table = (struct Medals*)malloc(sizeof(struct Medals)*n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter country name: ");
        scanf("%s", table[i].country);
        printf("Enter number of gold medals: ");
        scanf("%d", &table[i].gold);
        printf("Enter number of silver medals: ");
        scanf("%d", &table[i].silver);
        printf("Enter number of bronze medals: ");
        scanf("%d", &table[i].bronze);
    }
    return table;
}

void displayMedalTable(struct Medals *table, int n)
{
    printf("\nCountry\tGold\tSilver\tBronze\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t",table[i].country);
        printf("%d\t",table[i].gold);
        printf("%d\t",table[i].silver);
        printf("%d\t",table[i].bronze);
        printf("\n");
    }
}

int getGoldTotal(struct Medals *table,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=table[i].gold;
    }
    return sum;
}

void sortTable(struct Medals *table,int n)
{
    struct Medals temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(table[i].gold<table[j].gold)
            {
                temp = table[i];
                table[i] = table[j];
                table[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of countries: ");
    scanf("%d",&n);
    printf("\n");
    struct Medals *table = createMedalTable(n);
    printf("\nMedal Table:\n");
    displayMedalTable(table,n);
    printf("\nGold total: %d",getGoldTotal(table,n));
    printf("\n\nMedal Table sorted by Gold medals:\n");
    sortTable(table,n);
    displayMedalTable(table,n);
    return 0;
}