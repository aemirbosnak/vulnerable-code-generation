//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine{
    char name[50];
    float price;
    int quantity;
};

void add_medicine(struct Medicine *medicine){
    printf("\nEnter the name of the medicine: ");
    scanf("%s", medicine->name);
    printf("\nEnter the price of the medicine: ");
    scanf("%f", &medicine->price);
    printf("\nEnter the quantity of the medicine: ");
    scanf("%d", &medicine->quantity);
}

void display_medicine(struct Medicine medicine){
    printf("%-20s%-10.2f%-10d\n", medicine.name, medicine.price, medicine.quantity);
}

void display_all_medicines(struct Medicine *medicine, int count){
    printf("\n\n%-20s%-10s%-10s\n", "Medicine Name", "Price", "Quantity");
    for(int i=0; i<count; i++){
        display_medicine(medicine[i]);
    }
}

int search_medicine(struct Medicine *medicine, int count, char *name){
    for(int i=0; i<count; i++){
        if(strcmp(medicine[i].name, name)==0){
            return i;
        }
    }
    return -1;
}

void edit_medicine(struct Medicine *medicine){
    int choice;
    float price;
    int quantity;
    printf("\n\nWhat do you want to edit?\n\n1.Price\n2.Quantity\n\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice==1){
        printf("\nEnter the new price: ");
        scanf("%f", &price);
        medicine->price = price;
        printf("\nPrice updated successfully.\n");
    }
    else if(choice==2){
        printf("\nEnter the new quantity: ");
        scanf("%d", &quantity);
        medicine->quantity = quantity;
        printf("\nQuantity updated successfully.\n");
    }
    else{
        printf("\nInvalid choice entered.\n");
    }
}

void delete_medicine(struct Medicine *medicine, int count, int position){
    for(int i = position; i < count-1; i++){
        strcpy(medicine[i].name, medicine[i+1].name);
        medicine[i].price = medicine[i+1].price;
        medicine[i].quantity = medicine[i+1].quantity;
    }
    printf("\nMedicine deleted successfully.\n");
}

void main(){
    struct Medicine *medicines;
    int count = 0;
    int choice, position;
    char name[50];
    medicines = (struct Medicine*)malloc(sizeof(struct Medicine));
    do{
        printf("\n\nMedical Store Management\n\n1.Add a medicine\n2.Display all medicines\n3.Search for a medicine\n4.Edit a medicine\n5.Delete a medicine\n6.Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: //add
                count++;
                medicines = (struct Medicine*)realloc(medicines, count*sizeof(struct Medicine));
                add_medicine(&medicines[count-1]);
                printf("\nMedicine added successfully.\n");
                break;
            case 2: //display all
                if(count>0){
                    display_all_medicines(medicines, count);
                }
                else{
                    printf("\nNo medicines added yet.\n");
                }
                break;
            case 3: //search
                if(count>0){
                    printf("\nEnter the name of the medicine to search: ");
                    scanf("%s", name);
                    position = search_medicine(medicines, count, name);
                    if(position==-1){
                        printf("\nMedicine not found.\n");
                    }
                    else{
                        display_medicine(medicines[position]);
                    }
                }
                else{
                    printf("\nNo medicines added yet.\n");
                }
                break;
            case 4: //edit
                if(count>0){
                    printf("\nEnter the name of the medicine to edit: ");
                    scanf("%s", name);
                    position = search_medicine(medicines, count, name);
                    if(position==-1){
                        printf("\nMedicine not found.\n");
                    }
                    else{
                        edit_medicine(&medicines[position]);
                    }
                }
                else{
                    printf("\nNo medicines added yet.\n");
                }
                break;
            case 5: //delete
                if(count>0){
                    printf("\nEnter the name of the medicine to delete: ");
                    scanf("%s", name);
                    position = search_medicine(medicines, count, name);
                    if(position==-1){
                        printf("\nMedicine not found.\n");
                    }
                    else{
                        count--;
                        delete_medicine(medicines, count, position);
                        medicines = (struct Medicine*)realloc(medicines, count*sizeof(struct Medicine));
                    }
                }
                else{
                    printf("\nNo medicines added yet.\n");
                }
                break;
            case 6:
                printf("\nExiting from the program...\n");
                break;
            default:
                printf("\nInvalid choice entered.\n");
        }
    }while(choice!=6);
    free(medicines);
}