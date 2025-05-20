//FormAI DATASET v1.0 Category: Hotel Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[30];
    char address[50];
    char phone[15];
    int roomNo;
    int days;
    float totalBill;
};

struct room {
    int roomNo;
    char type[10];
    float price;
    int available;
};

struct customer custList[20];
struct room roomList[20];
int custCount = 0, roomCount = 0;

void printMenu();
void addCustomer();
void displayCustomer();
void checkOut();

int main() {
    int menuChoice;
    do {
        printMenu();
        scanf("%d", &menuChoice);
        switch (menuChoice) {
            case 1:
                addCustomer();
                break;
            case 2:
                displayCustomer();
                break;
            case 3:
                checkOut();
                break;
            case 4:
                printf("\nThank you for using our Hotel Management System!\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Please select from the menu.\n");
                break;
        }
    } while (menuChoice != 4);

    return 0;
}

void printMenu() {
    printf("\nWelcome to C Hotel Management System\n");
    printf("=====================================\n\n");
    printf("1. Add Customer\n");
    printf("2. Display Customer\n");
    printf("3. Check Out\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}

void addCustomer() {
    printf("\nAdd Customer\n");
    printf("============\n");
    printf("Enter customer name: ");
    scanf("%s", custList[custCount].name);
    printf("Enter customer address: ");
    scanf("%s", custList[custCount].address);
    printf("Enter customer phone no: ");
    scanf("%s", custList[custCount].phone);
    
    // Display available rooms
    printf("\nAvailable Rooms\n");
    printf("================\n");
    printf("Room No\tType\tPrice\n");
    for (int i = 0; i < roomCount; i++) {
        if (roomList[i].available) {
            printf("%d\t%s\t%.2f\n", roomList[i].roomNo, roomList[i].type, roomList[i].price);
        }
    }
    
    // Select room
    int roomNo, roomIndex;
    do {
        printf("\nEnter room no: ");
        scanf("%d", &roomNo);
        roomIndex = -1;
        for (int i = 0; i < roomCount; i++) {
            if (roomList[i].roomNo == roomNo) {
                roomIndex = i;
                break;
            }
        }
        if (roomIndex == -1) {
            printf("\nInvalid Room No! Please select from available rooms.\n");
        } else if (!roomList[roomIndex].available) {
            printf("\nRoom is not available! Please select another room.\n");
            roomIndex = -1;
        } else {
            custList[custCount].roomNo = roomNo;
            custList[custCount].totalBill += roomList[roomIndex].price; // Add room price to total bill
            roomList[roomIndex].available = 0; // Mark room as not available
        }
    } while (roomIndex == -1);
    
    // Enter no. of days
    printf("Enter number of days: ");
    scanf("%d", &custList[custCount].days);
    
    // Calculate total bill
    custList[custCount].totalBill += roomList[roomIndex].price * custList[custCount].days;
    
    // Increment customer count
    custCount++;
    
    printf("\nCustomer added successfully!\n");
}

void displayCustomer() {
    printf("\nDisplay Customer\n");
    printf("================\n");
    if (custCount == 0) {
        printf("No customers added yet!\n");
    } else {
        printf("Name\tAddress\tPhone No\tRoom\tDays\tTotal Bill\n");
        for (int i = 0; i < custCount; i++) {
            printf("%s\t%s\t%s\t%d\t%d\t%.2f\n", custList[i].name, custList[i].address, custList[i].phone, 
                    custList[i].roomNo, custList[i].days, custList[i].totalBill);
        }
    }
}

void checkOut() {
    printf("\nCheck Out\n");
    printf("=========\n");
    if (custCount == 0) {
        printf("No customers added yet!\n");
    } else {
        printf("Enter customer phone no: ");
        char phone[15];
        scanf("%s", phone);
        int custIndex = -1;
        for (int i = 0; i < custCount; i++) {
            if (strcmp(custList[i].phone, phone) == 0) {
                custIndex = i;
                break;
            }
        }
        if (custIndex == -1) {
            printf("\nInvalid Phone No! Customer not found.\n");
        } else {
            int roomIndex = -1;
            for (int i = 0; i < roomCount; i++) {
                if (roomList[i].roomNo == custList[custIndex].roomNo) {
                    roomIndex = i;
                    break;
                }
            }
            roomList[roomIndex].available = 1; // Mark room as available
            printf("\n%s checked out successfully! Total bill = $%.2f\n", custList[custIndex].name, custList[custIndex].totalBill);
            // Remove customer from list by shifting all customers to left
            for (int i = custIndex; i < custCount - 1; i++) {
                strcpy(custList[i].name, custList[i+1].name);
                strcpy(custList[i].address, custList[i+1].address);
                strcpy(custList[i].phone, custList[i+1].phone);
                custList[i].roomNo = custList[i+1].roomNo;
                custList[i].days = custList[i+1].days;
                custList[i].totalBill = custList[i+1].totalBill;
            }
            // Decrement customer count
            custCount--;
        }
    }
}