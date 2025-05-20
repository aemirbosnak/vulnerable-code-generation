//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine {
    char mname[30];
    int mcode;
    int quantity;
    float price;
};

//function to add new medicine data
void addMedicine(struct Medicine *m, int n) {
    printf("Enter details of medicine %d: \n", n+1);
    printf("Medicine name: ");
    scanf("%s", &(m+n)->mname);
    printf("Medicine code: ");
    scanf("%d", &(m+n)->mcode);
    printf("Quantity: ");
    scanf("%d", &(m+n)->quantity);
    printf("Price: ");
    scanf("%f", &(m+n)->price);
}

//function to display all medicine data
void displayAllMedicines(struct Medicine *m, int n) {
    printf("List of all medicines:\n");
    printf("Medicine Name\tMedicine Code\tQuantity\tPrice\n");
    for(int i=0;i<n;i++) {
        printf("%s\t%d\t%d\t\t%.2f\n", (m+i)->mname, (m+i)->mcode, (m+i)->quantity, (m+i)->price);
    }
}

//function to search for a medicine by name
void searchMedicine(struct Medicine *m, int n) {
    char searchName[30];
    int found = 0;
    printf("Enter name of medicine to search: ");
    scanf("%s", searchName);
    for(int i=0;i<n;i++) {
        if(strcmp(searchName, (m+i)->mname)==0) {
            printf("Medicine Name\tMedicine Code\tQuantity\tPrice\n");
            printf("%s\t%d\t%d\t\t%.2f\n", (m+i)->mname, (m+i)->mcode, (m+i)->quantity, (m+i)->price);
            found = 1;
        }
    }
    if(found==0) printf("Medicine not found\n");
}

//function to update medicine quantity
void updateMedicineQuantity(struct Medicine *m, int n) {
    int code, qty;
    int found = 0;
    printf("Enter medicine code to update: ");
    scanf("%d", &code);
    for(int i=0;i<n;i++) {
        if(code==(m+i)->mcode) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &qty);
            (m+i)->quantity = qty;
            printf("Quantity updated successfully!\n");
        }
    }
    if(found==0) printf("Medicine not found\n");
}

int main() {
    struct Medicine *medicines;
    int n, choice;
    char exitChoice;
    printf("Enter number of medicines: ");
    scanf("%d", &n);
    medicines = malloc(n*sizeof(struct Medicine));
    //add new medicines
    for(int i=0;i<n;i++) {
        addMedicine(medicines, i);
    }
    //menu
    do {
        printf("1. Display all medicines\n2. Search for a medicine by name\n3. Update medicine quantity\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: displayAllMedicines(medicines, n);
                    break;
            case 2: searchMedicine(medicines, n);
                    break;
            case 3: updateMedicineQuantity(medicines, n);
                    break;
            case 4: printf("Are you sure you want to exit? (y/n)");
                    scanf(" %c", &exitChoice);
                    if(exitChoice=='y') exit(0);
                    break;
            default: printf("Invalid Choice!\n");
        }
    } while(1);

    free(medicines);
    return 0;
}