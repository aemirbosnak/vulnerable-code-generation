//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

struct user{
    char name[100];
    int id;
    int bid;
    int status;
};

struct item{
    char name[100];
    int id;
    int price;
    int status;
    struct user highest_bidder;
};

struct user login(){
    struct user temp;
    printf("Enter username: ");
    scanf("%s",temp.name);
    printf("Enter ID: ");
    scanf("%d",&temp.id);
    return temp;
}

void view_items(){
    FILE *fp;
    fp=fopen("items.txt","r");
    if(fp==NULL){
        printf("No items available\n");
        return;
    }
    char ch;
    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){
            printf("\n");
        }
        else{
            printf("%c",ch);
        }
    }
    fclose(fp);
}

void place_bid(){
    FILE *fp;
    fp=fopen("items.txt","a+");
    if(fp==NULL){
        printf("Cannot place bid\n");
        return;
    }
    struct user temp=login();
    struct item item;
    rewind(fp);
    while(fscanf(fp,"%s %d %d %d %s",item.name,&item.id,&item.price,&item.status,item.highest_bidder.name)!=EOF){
        if(strcmp(item.name,temp.name)==0){
            printf("You are already the highest bidder\n");
            fclose(fp);
            return;
        }
        else if(item.status==1){
            printf("Bidding closed for this item\n");
            fclose(fp);
            return;
        }
        else{
            if(temp.bid>item.highest_bidder.bid){
                item.highest_bidder=temp;
                fprintf(fp,"%s %d %d %d %s\n",item.name,item.id,item.price,1,temp.name);
            }
            else{
                printf("Your bid is lower than the highest bid\n");
            }
            fclose(fp);
            return;
        }
    }
    printf("Item not found\n");
    fclose(fp);
}

void digital_auction(){
    char ch;
    while(1){
        system("clear");
        printf("1. View items\n2. Place bid\n3. Exit\n");
        scanf("%c",&ch);
        switch(ch){
            case '1':
                view_items();
                break;
            case '2':
                place_bid();
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

int main(){
    digital_auction();
    return 0;
}