//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[20];
    int code;
    int quantity;
};

int main() {
    int option, index, code, quantity, search_code, i, found=0;
    struct Item items[50];
    while (1) {
        printf("\n1. Add item\n2. View all items\n3. Search item\n4. Update item\n5. Remove item\n6. Exit\nEnter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1: {
                if(index < 50) {
                    printf("\nEnter name: ");
                    scanf("%s", items[index].name);
                    printf("Enter code: ");
                    scanf("%d", &items[index].code);
                    printf("Enter quantity: ");
                    scanf("%d", &items[index].quantity);
                    index++;
                }
                else {
                    printf("\nMaximum limit reached!\n");
                }
                break;
            }
            case 2: {
                if(index == 0) {
                    printf("\nNo items found!\n");
                }
                else {
                    printf("\nName\tCode\tQuantity\n");
                    for(i=0; i<index; i++) {
                        printf("%s\t%d\t%d\n", items[i].name, items[i].code, items[i].quantity);
                    }
                }
                break;
            }
            case 3: {
                if(index == 0) {
                    printf("\nNo items found!\n");
                }
                else {
                    printf("\nEnter code to search: ");
                    scanf("%d", &search_code);
                    for(i=0; i<index; i++) {
                        if(search_code == items[i].code) {
                            found = 1;
                            printf("\nName: %s\nCode: %d\nQuantity: %d\n", items[i].name, items[i].code, items[i].quantity);
                            break;
                        }
                    }
                    if(found == 0) {
                        printf("\nItem not found!\n");
                    }
                }
                break;
            }
            case 4: {
                if(index == 0) {
                    printf("\nNo items found!\n");
                }
                else {
                    printf("\nEnter code to update: ");
                    scanf("%d", &code);
                    found = 0;
                    for(i=0; i<index; i++) {
                        if(code == items[i].code) {
                            found = 1;
                            printf("\nEnter new quantity: ");
                            scanf("%d", &quantity);
                            items[i].quantity = quantity;
                            break;
                        }
                    }
                    if(found == 0) {
                        printf("\nItem not found!\n");
                    }
                }
                break;
            }
            case 5: {
                if(index == 0) {
                    printf("\nNo items found!\n");
                }
                else {
                    printf("\nEnter code to remove: ");
                    scanf("%d", &code);
                    found = 0;
                    for(i=0; i<index; i++) {
                        if(code == items[i].code) {
                            found = 1;
                            index--;
                            for(int j=i; j<index; j++) {
                                strcpy(items[j].name, items[j+1].name);
                                items[j].code = items[j+1].code;
                                items[j].quantity = items[j+1].quantity;
                            }
                            break;
                        }
                    }
                    if(found == 0) {
                        printf("\nItem not found!\n");
                    }
                }
                break;
            }
            case 6: {
                printf("\nExiting program...\n");
                exit(0);
            }
            default: {
                printf("\nInvalid option!\n");
            }
        }
    }
    return 0;
}