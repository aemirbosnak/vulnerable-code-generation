//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    int quantity;
    float price;
} s[50];

int main() {
    int n, i, ch;
    printf("Enter the number of medicines: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("\nEnter medicine ID: ");
        scanf("%d", &s[i].id);
        printf("Enter medicine name: ");
        scanf("%s", s[i].name);
        printf("Enter quantity available: ");
        scanf("%d", &s[i].quantity);
        printf("Enter price per unit: ");
        scanf("%f", &s[i].price);
    }
    while(1) {
        printf("\n1.Display all medicines");
        printf("\n2.Search a medicine");
        printf("\n3.Purchase a medicine");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: {
                printf("\nID\tMedicine\tQuantity\tPrice");
                for(i=0; i<n; i++)
                    printf("\n%d\t%s\t%d\t\t%.2f", s[i].id, s[i].name, s[i].quantity, s[i].price);
                break;
            }
            case 2: {
                int search_id, flag=0;
                printf("\nEnter medicine ID to search: ");
                scanf("%d", &search_id);
                for(i=0; i<n; i++) {
                    if(s[i].id == search_id) {
                        printf("\nID\tMedicine\tQuantity\tPrice");
                        printf("\n%d\t%s\t%d\t\t%.2f", s[i].id, s[i].name, s[i].quantity, s[i].price);
                        flag = 1;
                    }
                }
                if(!flag)
                    printf("\nMedicine not found!");
                break;
            }
            case 3: {
                int purchase_id, purchase_qty, flag=0;
                float total_cost;
                printf("\nEnter medicine ID to purchase: ");
                scanf("%d", &purchase_id);
                for(i=0; i<n; i++) {
                    if(s[i].id == purchase_id) {
                        flag = 1;
                        printf("Enter quantity to purchase: ");
                        scanf("%d", &purchase_qty);
                        if(s[i].quantity < purchase_qty) {
                            printf("\nNot enough quantity available!");
                            break;
                        }
                        else {
                            total_cost = s[i].price * purchase_qty;
                            printf("\nTotal cost: %.2f", total_cost);
                            s[i].quantity -= purchase_qty;
                            printf("\nPurchase successful!");
                            break;
                        }
                    }
                }
                if(!flag)
                    printf("\nMedicine not found!");
                break;
            }
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}