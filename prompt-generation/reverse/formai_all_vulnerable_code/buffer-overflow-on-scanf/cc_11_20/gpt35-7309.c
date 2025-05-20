//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[50];
    int stock;
    float price;
};

typedef struct medicine Medicine; //alias `Medicine` for `struct medicine`

int main() {
    int choice, num;
    Medicine *medList = NULL; //list of medicines initially empty
    int medCount = 0; //number of medicines in the list

    printf("Welcome to the Medical Store Management System\n\n");

    while(1) {
        printf("Please select an option:\n");
        printf("1. Add medicine\n");
        printf("2. Update medicine stock\n");
        printf("3. Remove medicine\n");
        printf("4. Display all medicines\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1: //Add medicine
                if(medList == NULL){
                    medList = (Medicine*)malloc(sizeof(Medicine)); //allocate memory for one medicine
                }
                else {
                    medList = (Medicine*)realloc(medList, (medCount+1)*sizeof(Medicine)); //increase size of medicine list by one
                }

                printf("Enter medicine name: ");
                scanf("%s", medList[medCount].name);

                printf("Enter medicine stock: ");
                scanf("%d", &medList[medCount].stock);

                printf("Enter medicine price: ");
                scanf("%f", &medList[medCount].price);

                medCount++;
                break;

            case 2: //Update medicine stock
                printf("Enter medicine index: ");
                scanf("%d", &num);

                if(num<1 || num>medCount) {
                    printf("Invalid index\n");
                }
                else {
                    printf("Enter new stock value: ");
                    scanf("%d", &medList[num-1].stock);
                }

                break;

            case 3: //Remove medicine
                printf("Enter medicine index: ");
                scanf("%d", &num);

                if(num<1 || num>medCount) {
                    printf("Invalid index\n");
                }
                else {
                    for(int i=num-1;i<medCount-1;i++) { //shift medicines left tofill void created by removed medicine
                        medList[i] = medList[i+1];
                    }
                    
                    medCount--;
                    if(medCount == 0){
                        free(medList); //if there are no medicines, free the memory allocated for `medList`
                        medList = NULL; //reset to empty list
                    }
                    else {
                        medList = (Medicine*)realloc(medList, medCount*sizeof(Medicine)); //decrease size of medicine list by one
                    }
                }

                break;

            case 4: //Display all medicines
                printf("%-4s%-20s%-10s%-10s\n", "ID", "Name", "Stock", "Price"); //display table header
                for(int i=0;i<medCount;i++) {
                    printf("%-4d%-20s%-10d%-10.2f\n", i+1, medList[i].name, medList[i].stock, medList[i].price); //display medicine details
                }
                break;

            case 5: //Exit
                free(medList); //free the memory allocated for `medList`
                printf("\nThank you for using the Medical Store Management System\n");
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
        }

        printf("\n\n");
    }

    return 0;
}