//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defining structures for medicine and customer details */
struct medicine{
    int med_id;
    char med_name[50];
    int med_price;
}med[100]; 

struct customer{
    char cust_name[50];
    int cust_id;
    int cust_age;
    int med_id;
    int med_quantity;
    int total_price;
}cust[100];

int main()
{
    int choice;
    int i, j, k;
    while(1)
    {
        printf("\n------------- Medical Store Management System ------------\n\n");
        printf("Enter 1 to Add Medicine List\nEnter 2 to Display all Medicines\nEnter 3 to Purchase Medicine\nEnter 4 to Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("\n~~~~~~~~~~~~ Add Medicine List ~~~~~~~~~~~~~~\n\n");
                printf("How many medicines do you want to add? : ");
                int num_add;
                scanf("%d",&num_add);
                
                for(i = 0; i < num_add; i++)
                {
                    printf("\nEnter Medicine ID: ");
                    scanf("%d",&med[i].med_id);
                    
                    printf("Enter Medicine Name: ");
                    scanf("%s",&med[i].med_name);
                    
                    printf("Enter Medicine Price: ");
                    scanf("%d",&med[i].med_price);
                }
                break;
                
            case 2:
                printf("\n~~~~~~~~~~~~ Displaying all Medicines ~~~~~~~~~~~~~~\n\n");
                printf("ID\tName\tPrice\n\n");
                for(j = 0; j < num_add; j++)
                {
                    printf("%d\t%s\t%d\n",med[j].med_id, med[j].med_name, med[j].med_price);
                }
                
                break;
                
            case 3:
                printf("\n~~~~~~~~~~~~ Purchase Medicine ~~~~~~~~~~~~~~\n\n");
                printf("\nEnter your Name: ");
                scanf("%s",&cust[k].cust_name);
                
                printf("Enter your ID: ");
                scanf("%d",&cust[k].cust_id);
                
                printf("Enter your Age: ");
                scanf("%d",&cust[k].cust_age);
                
                printf("\nAvailable Medicines:\n\n");
                printf("ID\tName\tPrice\n\n");
                for(j = 0; j < num_add; j++)
                {
                    printf("%d\t%s\t%d\n",med[j].med_id, med[j].med_name, med[j].med_price);
                }
                
                printf("\nEnter Medicine ID: ");
                scanf("%d",&cust[k].med_id);
                
                printf("Enter Quantity: ");
                scanf("%d",&cust[k].med_quantity);
                
                for(i = 0; i<num_add; i++)
                {
                    if(med[i].med_id == cust[k].med_id)
                    {
                        cust[k].total_price = cust[k].med_quantity * med[i].med_price;
                        printf("\nYou have successfully purchased %d %s.\n",cust[k].med_quantity,med[i].med_name);
                        printf("Total Price: %d\n",cust[k].total_price);
                    }
                }
                k++;
                
                break;
                
            case 4:
                printf("\n~~~~~~~~~~~~ Thank You For Using This Program ~~~~~~~~~~~~~~\n");
                exit(0);
                break;
                
            default:
                printf("\n~~~~~~~~~~~~ Invalid Choice ~~~~~~~~~~~~~~\n");
                break;
        }
    }
    return 0;
}