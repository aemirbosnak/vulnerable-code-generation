//FormAI DATASET v1.0 Category: Digital Diary ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to Digital Diary!");
    printf("\nEnter Password:");

    int pass = 1234, user_pass, menu_select, d, m, y, i;
    char task[200][200], date[200][200], time[200][200], description[300][300];
    char file_name[100];

    printf("\nPassword: ");
    scanf("%d",&user_pass);
    if(user_pass!=pass)
    {
        printf("Incorrect password!");
        return 0;
    }
    else
    {
        printf("\nAccess Granted!");
        while(1)
        {
            printf("\n\nMenu:\n1.New Entry\n2.View Entry\n3.Exit\nSelect an option(1,2,3):");
            scanf("%d",&menu_select);

            if(menu_select==1)
            {
                printf("\nEnter date(dd/mm/yyyy): ");
                scanf("%d/%d/%d",&d,&m,&y);

                printf("\nEnter task name: ");
                scanf("%s",task[i]);

                printf("\nEnter time(hh:mm): ");
                scanf("%s",time[i]);

                printf("\nEnter description: ");
                scanf("%s",description[i]);

                sprintf(file_name,"%d%d%d.txt",d,m,y);
                FILE *fptr = fopen(file_name,"a+");

                fprintf(fptr,"\n%s",task[i]);
                fprintf(fptr,"\n%s",time[i]);
                fprintf(fptr,"\n%s",description[i]);

                printf("\nEntry saved successfully!");
                fclose(fptr);

                i++;
            }

            else if(menu_select==2)
            {
                printf("\nEnter date(dd/mm/yyyy): ");
                scanf("%d/%d/%d",&d,&m,&y);

                sprintf(file_name,"%d%d%d.txt",d,m,y);
                FILE *fptr = fopen(file_name,"r");

                if(fptr==NULL)
                {
                    printf("\nNo entries found for the given date!");
                    continue;
                }
                else
                {
                    printf("\nTask\t\tTime\t\tDescription");
                    while(!feof(fptr))
                    {
                        fgets(task[200],200,fptr);
                        fgets(time[200],200,fptr);
                        fgets(description[300],300,fptr);

                        printf("%s\t%s\t%s",task[200],time[200],description[300]);
                    }
                    fclose(fptr);
                }
            }

            else if(menu_select==3)
            {
                printf("\nExiting Digital Diary!");
                break;
            }

            else
            {
                printf("\nInvalid Option!");
            }
        }
    }
    return 0;
}