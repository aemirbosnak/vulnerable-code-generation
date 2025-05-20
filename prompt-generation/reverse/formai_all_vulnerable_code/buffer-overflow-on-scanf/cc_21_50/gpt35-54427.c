//FormAI DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct guest{
    char name[50];
    int roomno;
    int days;
    char roomtype[15];
    int price;
}g;

int main(){
    int choice, i, flag=0;
    FILE *fp;
    //Opening the file
    fp=fopen("guests.dat","ab+");
    printf("\n\n\t\t*****Welcome to the C Hotel Management System*****\n\n");
    do{
        printf("\nEnter your choice:\n1. New Guest check-in\n2. Display all guests\n3. Search for a guest\n4. Modify guest details\n5. Delete guest details\n6. Exit the system\n\nChoice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                //Adding a new guest
                printf("\nEnter Guest name: ");
                scanf("%s",g.name);
                printf("\nEnter the room type [Single/Double/Family Suite]: ");
                scanf("%s",g.roomtype);
                printf("\nEnter the room no: ");
                scanf("%d",&g.roomno);
                printf("\nEnter no of days of stay: ");
                scanf("%d",&g.days);
                if(strcmp(g.roomtype,"Single")==0){         
                    g.price=g.days*1000;
                }
                else if(strcmp(g.roomtype,"Double")==0){
                    g.price=g.days*1500;
                }
                else if(strcmp(g.roomtype,"Family Suite")==0){
                    g.price=g.days*3000;
                }
                printf("\nTotal amount: %d",g.price);
                fwrite(&g,sizeof(g),1,fp);
                printf("\n\nGuest details added successfully!\n");
                break;

            case 2:
                //Displaying all guests
                rewind(fp);
                printf("\nGuest details:\n");
                while(fread(&g,sizeof(g),1,fp)==1){
                    printf("\n\nName: %s\nRoom No: %d\nRoom type: %s\nNo of days: %d\nTotal cost: %d",g.name,g.roomno,g.roomtype,g.days,g.price);
                }   
                break;

            case 3:
                //Searching for a guest
                printf("\nEnter room no to search: ");
                scanf("%d",&i);
                rewind(fp);
                while(fread(&g,sizeof(g),1,fp)==1){
                    if(g.roomno==i){
                        printf("\nName: %s\nRoom No: %d\nRoom type: %s\nNo of days: %d\nTotal cost: %d",g.name,g.roomno,g.roomtype,g.days,g.price);
                        flag=1;
                    }
                }   
                if(flag==0){
                    printf("\n\nNo guest found with this room number!");
                }
                break;

            case 4:
                //Modifying guest details
                printf("\nEnter the room no of guest to modify: ");
                scanf("%d",&i);
                rewind(fp);
                while(fread(&g,sizeof(g),1,fp)==1){
                    if(g.roomno==i){
                        flag=1;
                        printf("\nEnter new name: ");
                        scanf("%s",g.name);
                        printf("\nEnter new room type: ");
                        scanf("%s",g.roomtype);
                        printf("\nEnter new number of days of stay: ");
                        scanf("%d",&g.days);
                        printf("\nTotal amount to be paid: ");
                        if(strcmp(g.roomtype,"Single")==0){         
                            g.price=g.days*1000;
                        }
                        else if(strcmp(g.roomtype,"Double")==0){
                            g.price=g.days*1500;
                        }
                        else if(strcmp(g.roomtype,"Family Suite")==0){
                            g.price=g.days*3000;
                        }
                        printf("\nTotal amount: %d",g.price);
                        fseek(fp,-sizeof(g), SEEK_CUR);
                        fwrite(&g,sizeof(g),1,fp);
                        printf("\n\nGuest details modified successfully!\n");
                    }
                }
                if(flag==0){
                    printf("\n\nNo guest found with this room number!");
                }
                break;

            case 5:
                //Deleting guest details
                flag=0;
                printf("\nEnter room no of guest details to be deleted: ");
                scanf("%d",&i);
                rewind(fp);
                while(fread(&g,sizeof(g),1,fp)==1){
                    if(g.roomno==i){
                        flag=1;
                        fseek(fp,-sizeof(g), SEEK_CUR);
                        fwrite(&g,sizeof(g),1,fp);
                        printf("\n\nGuest details deleted successfully!\n");
                    }
                }
                if(flag==0){
                    printf("\n\nNo guest found with this room number!");
                }
                break;

            case 6:
                //Exiting the system
                printf("\n\n*****Thanks for using the C Hotel Management System*****\n\n");
                break;

            default:
                printf("\n\nInvalid choice!\n");     
        }
    }while(choice!=6);
    return 0;
}