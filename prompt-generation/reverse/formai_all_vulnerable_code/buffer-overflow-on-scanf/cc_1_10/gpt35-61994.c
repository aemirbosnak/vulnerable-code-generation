//FormAI DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

struct room {
    int room_no;
    char type[20];
    int price;
    char status[20];
};

void display_room(struct room r) {
    printf("\nRoom No: %d\n", r.room_no);
    printf("Room Type: %s\n", r.type);
    printf("Price: %d\n", r.price);
    printf("Status: %s\n", r.status);
}

void display_all(struct room r[], int n) {
    int i;
    for(i=0;i<n;i++) {
        display_room(r[i]);
    }
}

int main() {
    struct room r[100];
    int n, ch, i;
    char cont;
    
    printf("Enter number of rooms: ");
    scanf("%d", &n);
    
    for(i=0;i<n;i++) {
        r[i].room_no = i+1;
        printf("\nEnter details of Room %d:\n", r[i].room_no);
        printf("Room Type: ");
        scanf("%s", r[i].type);
        printf("Price: ");
        scanf("%d", &r[i].price);
        strcpy(r[i].status, "Available");
    }
    
    do {
        printf("\nHotel Management System:\n");
        printf("1. Display All Rooms\n");
        printf("2. Search Room By Room No\n");
        printf("3. Search Room By Room Type\n");
        printf("4. Book A Room\n");
        printf("5. Exit\n");
        
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                display_all(r, n);
                break;
            case 2:
                {
                    int rn, j;
                    printf("\nEnter Room No: ");
                    scanf("%d", &rn);
                    for(j=0;j<n;j++) {
                        if(r[j].room_no == rn) {
                            display_room(r[j]);
                            break;
                        }
                    }
                    if(j==n) {
                        printf("\nRoom Not Found!\n");
                    }
                }
                break;
            case 3:
                {
                    char rt[20];
                    int j;
                    printf("\nEnter Room Type: ");
                    scanf("%s", rt);
                    for(j=0;j<n;j++) {
                        if(strcmp(r[j].type, rt) == 0) {
                            display_room(r[j]);
                        }
                    }
                }
                break;
            case 4:
                {
                    int rn, j;
                    printf("\nEnter Room No: ");
                    scanf("%d", &rn);
                    for(j=0;j<n;j++) {
                        if(r[j].room_no == rn) {
                            if(strcmp(r[j].status, "Available") == 0) {
                                strcpy(r[j].status, "Booked");
                                printf("\nBooking Successful!\n");
                            }
                            else {
                                printf("\nRoom Already Booked!\n");
                            }
                            break;
                        }
                    }
                    if(j==n) {
                        printf("\nRoom Not Found!\n");
                    }
                }
                break;
            case 5:
                break;
            default:
                printf("\nInvalid Choice!\n");
        }
        if(ch!=5) {
            printf("\nDo You Want To Continue (y/n): ");
            scanf(" %c", &cont);
        }
    } while(ch!=5 && cont=='y');
    
    return 0;
}