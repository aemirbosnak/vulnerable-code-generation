//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    while(1) {
        printf("Enter 1 to Add a Stock\nEnter 2 to Remove a Stock\nEnter 3 to Display Stocks\nEnter 4 to Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                system("clear");
                printf("Enter Stock Name: ");
                char name[100];
                scanf("%s",name);
                printf("Enter Stock Price: ");
                float price;
                scanf("%f",&price);
                printf("\nStock %s added successfully with price %.2f\n",name,price);
                break;
            case 2:
                system("clear");
                printf("Enter Stock Name to Remove: ");
                char remname[100];
                scanf("%s",remname);
                remove(remname);
                printf("\nStock %s removed successfully\n",remname);
                break;
            case 3:
                system("clear");
                FILE *fp;
                fp=fopen("stocks.txt","r");
                if(fp==NULL) {
                    printf("\nNo Stocks Found!!\n");
                }
                else {
                    char ch;
                    while((ch=fgetc(fp))!=EOF) {
                        printf("%c",ch);
                    }
                    fclose(fp);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice!! Please try again\n");
        }
    }
    return 0;
}