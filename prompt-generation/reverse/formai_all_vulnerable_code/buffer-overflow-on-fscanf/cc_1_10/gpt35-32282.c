//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure for medicine details
struct medicine_details {
    int id;
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
}med;

// Declare the functions
void add_medicine();
void display_medicine();
void search_medicine();
void update_medicine();
void delete_medicine();

int main()
{
    int choice;
    while(1) // Infinite loop to display menu
    {
        printf("\n----Medical Store Management System----\n");
        printf("\n1. Add medicine\n2. Display medicine details\n3. Search medicine\n4. Update medicine\n5. Delete medicine\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: add_medicine();
                    break;
            case 2: display_medicine();
                    break;
            case 3: search_medicine();
                    break;
            case 4: update_medicine();
                    break;
            case 5: delete_medicine();
                    break;
            case 6: exit(0);
            default: printf("\nInvalid choice entered!");
        }
    }
    return 0;
}

void add_medicine(){
    FILE *fp;
    fp=fopen("medicines.txt","a"); // Opening the file in append mode
    printf("\nEnter the medicine details: ");
    printf("\nMedicine ID: ");
    scanf("%d",&med.id);
    printf("\nMedicine name: ");
    scanf("%s",med.name);
    printf("\nMedicine manufacturer: ");
    scanf("%s",med.manufacturer);
    printf("\nMedicine quantity: ");
    scanf("%d",&med.quantity);
    printf("\nMedicine price: ");
    scanf("%f",&med.price);
    fprintf(fp,"%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n",med.id,med.name,med.manufacturer,med.quantity,med.price);
    fclose(fp); // Close the file
    printf("\nMedicine details added successfully!");
}

void display_medicine(){
    FILE *fp;
    fp=fopen("medicines.txt","r"); // Opening the file in read mode
    if(fp==NULL){
        printf("\nError: Unable to open the medicines file!");
        exit(1);
    }
    printf("\n=============================================================================\n");
    printf("%10s\t|%20s\t|%20s\t|%15s\t|%10s\t\n","ID","Name","Manufacturer","Quantity","Price");
    printf("=============================================================================\n");
    while(fscanf(fp,"%d\t\t%s\t\t%s\t\t%d\t\t%f\n",&med.id,med.name,med.manufacturer,&med.quantity,&med.price)!=EOF){
        printf("%10d\t|%20s\t|%20s\t|%15d\t|%10.2f\t\n",med.id,med.name,med.manufacturer,med.quantity,med.price);
    }
    printf("=============================================================================\n");
    fclose(fp); // Close the file
}

void search_medicine(){
    FILE *fp;
    int id,found=0;
    fp=fopen("medicines.txt","r"); // Opening the file in read mode
    if(fp==NULL){
        printf("\nError: Unable to open the medicines file!");
        exit(1);
    }
    printf("\nEnter the medicine ID to be searched: ");
    scanf("%d",&id);
    while(fscanf(fp,"%d\t\t%s\t\t%s\t\t%d\t\t%f\n",&med.id,med.name,med.manufacturer,&med.quantity,&med.price)!=EOF){
        if(med.id==id){
            found=1;
            printf("\nMedicine details found: ");
            printf("\nMedicine ID: %d\nMedicine name: %s\nMedicine manufacturer: %s\nMedicine quantity: %d\nMedicine price: %.2f\n",med.id,med.name,med.manufacturer,med.quantity,med.price);
        }
    }
    if(found==0){
        printf("\nError: Medicine not found!");
    }
    fclose(fp); // Close the file
}

void update_medicine(){
    FILE *f1, *f2;
    int id, found=0;
    f1=fopen("medicines.txt","r"); // Opening the file in read mode
    f2=fopen("temp.txt","w"); // Opening the temporary file in write mode
    if(f1==NULL){
        printf("\nError: Unable to open the medicines file!");
        exit(1);
    }
    printf("\nEnter the medicine ID to be updated: ");
    scanf("%d",&id);
    while(fscanf(f1,"%d\t\t%s\t\t%s\t\t%d\t\t%f\n",&med.id,med.name,med.manufacturer,&med.quantity,&med.price)!=EOF){
        if(med.id==id){
            found=1;
            printf("\nEnter the new details for the medicine: ");
            printf("\nMedicine name: ");
            scanf("%s",med.name);
            printf("\nMedicine manufacturer: ");
            scanf("%s",med.manufacturer);
            printf("\nMedicine quantity: ");
            scanf("%d",&med.quantity);
            printf("\nMedicine price: ");
            scanf("%f",&med.price);
            fprintf(f2,"%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n",med.id,med.name,med.manufacturer,med.quantity,med.price);
            printf("\nMedicine details updated!");
        }
        else{
            fprintf(f2,"%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n",med.id,med.name,med.manufacturer,med.quantity,med.price);
        }
    }
    if(found==0){
        printf("\nError: Medicine not found!");
    }
    fclose(f1); // Close the file
    fclose(f2);
    remove("medicines.txt"); // Removing the old file
    rename("temp.txt","medicines.txt"); // Renaming the temporary file to the original file name
}

void delete_medicine(){
    FILE *f1, *f2;
    int id, found=0;
    f1=fopen("medicines.txt","r"); // Opening the file in read mode
    f2=fopen("temp.txt","w"); // Opening the temporary file in write mode
    if(f1==NULL){
        printf("\nError: Unable to open the medicines file!");
        exit(1);
    }
    printf("\nEnter the medicine ID to be deleted: ");
    scanf("%d",&id);
    while(fscanf(f1,"%d\t\t%s\t\t%s\t\t%d\t\t%f\n",&med.id,med.name,med.manufacturer,&med.quantity,&med.price)!=EOF){
        if(med.id==id){
            found=1;
            printf("\nMedicine details deleted successfully!");
        }
        else{
            fprintf(f2,"%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n",med.id,med.name,med.manufacturer,med.quantity,med.price);
        }
    }
    if(found==0){
        printf("\nError: Medicine not found!");
    }
    fclose(f1); // Close the file
    fclose(f2);
    remove("medicines.txt"); // Removing the old file
    rename("temp.txt","medicines.txt"); // Renaming the temporary file to the original file name
}