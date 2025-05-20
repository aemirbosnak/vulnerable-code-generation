//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct
{
    int day;
    int month;
    int year;
    char entry[100];
}Diary;

void addEntry(Diary* d)
{
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d",&d->day,&d->month,&d->year);
    printf("Enter your diary entry:\n");
    fgets(d->entry,sizeof(d->entry),stdin);
    printf("\n");
}

void viewEntries(Diary d[], int n)
{
    system("clear");
    printf("Diary entries:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d/%d/%d - %s\n",d[i].day,d[i].month,d[i].year,d[i].entry);
    }
}

void searchEntry(Diary d[], int n)
{
    char search[100];
    printf("Enter the date to search (dd/mm/yyyy): ");
    scanf("%s",search);
    int found=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(search,d[i].entry)==0)
        {
            printf("Diary entry found:\n");
            printf("%s\n",d[i].entry);
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Diary entry not found.\n");
    }
}

void deleteEntry(Diary d[], int* n)
{
    printf("Enter the date to delete (dd/mm/yyyy): ");
    scanf("%s",d[*n-1].entry);
    for(int i=0;i<*n;i++)
    {
        if(strcmp(d[i].entry,d[*n-1].entry)==0)
        {
            for(int j=i;j<*n-1;j++)
            {
                d[j]=d[j+1];
            }
            (*n)--;
            break;
        }
    }
}

int main()
{
    Diary d[100];
    int n=0;
    char cont;
    do
    {
        system("clear");
        printf("1. Add diary entry\n2. View diary entries\n3. Search diary entry\n4. Delete diary entry\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&cont);
        switch(cont)
        {
            case 1:
                addEntry(&d[n]);
                n++;
                break;
            case 2:
                viewEntries(d,n);
                break;
            case 3:
                searchEntry(d,n);
                break;
            case 4:
                deleteEntry(d,&n);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }while(cont!=5);
    return 0;
}