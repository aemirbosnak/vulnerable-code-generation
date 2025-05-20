//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int total_amt=0;

void *order(void *args)
{
    int *cost=(int*)args;
    printf("\nPreparing your order...\n");
    sleep(2);
    printf("\nYour order is ready.\nAmount payable for your order is: $%d\n",*cost);
    total_amt+=(*cost);
    pthread_exit(NULL);
}

int main()
{
    printf("\nWelcome to C Cafe!\n");
    printf("**********************************\n");
    printf("Menu Card: \n");
    printf("1. Espresso - $2\n2. Cappuccino - $3\n3. Latte - $4\n");
    printf("**********************************\n");

    pthread_t tid[5];
    int item_code[5];
    int items_count=0;

    char choice;
    do
    {
        printf("\nEnter your item code: ");
        scanf("%d",&item_code[items_count]);

        switch(item_code[items_count])
        {
            case 1:
                printf("\nEnter quantity: ");
                scanf("%d",&item_code[items_count]);
                pthread_create(&tid[items_count],NULL,order,&item_code[items_count]);
                items_count++;
                break;

            case 2:
                printf("\nEnter quantity: ");
                scanf("%d",&item_code[items_count]);
                pthread_create(&tid[items_count],NULL,order,&item_code[items_count]);
                items_count++;
                break;

            case 3:
                printf("\nEnter quantity: ");
                scanf("%d",&item_code[items_count]);
                pthread_create(&tid[items_count],NULL,order,&item_code[items_count]);
                items_count++;
                break;

            default:
                printf("\nInvalid item code entered!\n");
                break;
        }

        printf("\nDo you want to order anything else? (y/n): ");
        scanf(" %c",&choice);
    } while (choice=='y' || choice=='Y');

    for(int i=0;i<items_count;i++)
    {
        pthread_join(tid[i],NULL);
    }

    printf("\nTotal amount payable for your order is: $%d\n",total_amt);

    return 0;
}