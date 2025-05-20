//FormAI DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include<stdio.h>
#include<string.h>

struct guest{
    int room_no;
    char name[20];
    char address[50];
    char checkin_date[10];
    char checkout_date[10];
};

void displayMenu(){
    printf("\n---------------------------");
    printf("\n\t1. Add Guest");
    printf("\n\t2. Search Guest");
    printf("\n\t3. Modify Guest Details");
    printf("\n\t4. Delete Guest");
    printf("\n\t5. Display All Guests");
    printf("\n\t6. Exit");
    printf("\n---------------------------");
}

void addGuest(struct guest g[], int n){
    printf("\nEnter the details of guest %d:", n);
    fflush(stdin);
    printf("\nRoom Number: ");
    scanf("%d", &g[n-1].room_no);
    printf("Name: ");
    scanf("%s", g[n-1].name);
    printf("Address: ");
    scanf("%s", g[n-1].address);
    printf("Check-in Date: ");
    scanf("%s", g[n-1].checkin_date);
    printf("Check-out Date: ");
    scanf("%s", g[n-1].checkout_date);
    printf("\nGuest added successfully!\n");
}

int searchGuest(struct guest g[], int n, int id){
    for(int i=0; i<n; i++){
        if(g[i].room_no == id){
            return i;
        }
    }
    return -1;
}

void modifyGuest(struct guest g[], int id){
    int index = searchGuest(g, 10, id);
    if(index != -1){
        printf("\nEnter Modified Guest Details:");
        fflush(stdin);
        printf("\nRoom Number: ");
        scanf("%d", &g[index].room_no);
        printf("Name: ");
        scanf("%s", g[index].name);
        printf("Address: ");
        scanf("%s", g[index].address);
        printf("Check-in Date: ");
        scanf("%s", g[index].checkin_date);
        printf("Check-out Date: ");
        scanf("%s", g[index].checkout_date);
        printf("\nGuest details modified successfully!\n");
    }
    else{
        printf("\nGuest not found!\n");
    }
}

void deleteGuest(struct guest g[], int id){
    int index = searchGuest(g, 10, id);
    if(index != -1){
        for(int i=index; i<9; i++){
            g[i] = g[i+1];
        }
        printf("\nGuest deleted successfully!\n");
    }
    else{
        printf("\nGuest not found!\n");
    }
}

void displayAllGuests(struct guest g[], int n){
    printf("\n---------------------------");
    printf("\n\tGuest Details");
    printf("\n---------------------------");
    printf("\nRoom No.\tName\tAddress\tCheck-in Date\tCheck-out Date");
    for(int i=0; i<n; i++){
        printf("\n%d\t\t%s\t%s\t%s\t%s", g[i].room_no, g[i].name, g[i].address, g[i].checkin_date, g[i].checkout_date);
    }
}

int main(){
    int choice, id, count=0;
    struct guest guests[10];
    do{
        displayMenu();
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        switch(choice){
            case 1: if(count<10){
                        count++;
                        addGuest(guests, count);
                    }
                    else{
                        printf("\nHotel is full!");
                    }
                    break;
            case 2: printf("\nEnter the room number of the guest: ");
                    scanf("%d",&id);
                    if(searchGuest(guests, count, id)!=-1){
                        printf("\nGuest found!");
                    }
                    else{
                        printf("\nGuest not found!");
                    }
                    break;
            case 3: printf("\nEnter the room number of the guest: ");
                    scanf("%d",&id);
                    modifyGuest(guests, id);
                    break;
            case 4: printf("\nEnter the room number of the guest: ");
                    scanf("%d",&id);
                    deleteGuest(guests, id);
                    count--;
                    break; 
            case 5: displayAllGuests(guests, count);
                    break;
            case 6: printf("\nExiting...");
                    break;
            default: printf("\nInvalid choice! Enter a valid choice (1-6).");
        }
    } while(choice!=6);
    return 0;
}