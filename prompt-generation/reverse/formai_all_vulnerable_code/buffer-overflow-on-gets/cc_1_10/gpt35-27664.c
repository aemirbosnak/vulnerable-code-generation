//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[30];
    char batch[20];
    char company[30];
    float price;
    int quantity;
};

void addMedicine(struct medicine arr[], int n);
void displayMedicine(struct medicine arr[], int n);
void searchMedicine(struct medicine arr[], int n, char searchName[]);
void updateMedicine(struct medicine arr[], int n, char batchNum[]);
void deleteMedicine(struct medicine arr[], int *n, char batchNum[]);

int main() {
    struct medicine medArr[50];
    int choice, n = 0;
    do {
        printf("\n MEDICAL STORE MANAGEMENT SYSTEM\n");
        printf(" 1. Add New Medicine\n");
        printf(" 2. Display All Medicines\n");
        printf(" 3. Search Medicine\n");
        printf(" 4. Update Medicine\n");
        printf(" 5. Delete Medicine\n");
        printf(" 6. Exit\n");
        printf(" Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine(medArr, n);
                n++;
                break;
            case 2:
                displayMedicine(medArr, n);
                break;
            case 3:
                {
                    char searchName[30];
                    printf("\n Enter the name of the medicine to search: ");
                    fflush(stdin);
                    gets(searchName);
                    searchMedicine(medArr, n, searchName);
                    break;
                }
            case 4:
                {
                    char batchNum[20];
                    printf("\n Enter the batch number of the medicine to update: ");
                    fflush(stdin);
                    gets(batchNum);
                    updateMedicine(medArr, n, batchNum);
                    break;
                }
            case 5:
                {
                    char batchNum[20];
                    printf("\n Enter the batch number of the medicine to delete: ");
                    fflush(stdin);
                    gets(batchNum);
                    deleteMedicine(medArr, &n, batchNum);
                    break;
                }
            case 6:
                exit(0);
            default:
                printf("\n Invalid Choice! Please try again!!");
                break;
        }
    } while(choice != 6);
    return 0;
}

void addMedicine(struct medicine arr[], int n) {
    FILE *fp;
    fp=fopen("medical-store.txt","a");
    printf("\n Enter Medicine Name: ");
    fflush(stdin);
    gets(arr[n].name);
    printf(" Enter batch number: ");
    fflush(stdin);
    gets(arr[n].batch);
    printf(" Enter Company: ");
    fflush(stdin);
    gets(arr[n].company);
    printf(" Enter Price: ");
    scanf("%f", &arr[n].price);
    printf(" Enter quantity: ");
    scanf("%d", &arr[n].quantity);
    fprintf(fp, "%s %s %s %.2f %d\n", arr[n].name, arr[n].batch, arr[n].company, arr[n].price, arr[n].quantity);
    fclose(fp);
    printf("\n Medicine added successfully!");
}

void displayMedicine(struct medicine arr[], int n) {
    FILE *fp;
    int i=0;
    char ch;
    fp=fopen("medical-store.txt", "r");
    printf("\n                                               Medicines available\n");
    printf(" =======================================================================================================\n");
    printf("|                          MEDICINE NAME                          |  BATCH NO  |   COMPANY  |   PRICE   | QUANTITY  |\n");
    printf(" -------------------------------------------------------------------------------------------------------\n");
    while(!feof(fp)){
         fscanf(fp, "%s %s %s %f %d\n", &arr[i].name, &arr[i].batch, &arr[i].company, &arr[i].price, &arr[i].quantity);
         printf("|%-65s|%-11s|%-12s|%-11.2f|%-11d|\n", arr[i].name, arr[i].batch, arr[i].company, arr[i].price, arr[i].quantity);
         i++;
    }
    printf(" --------------------------------------------------------------------------------------------------------\n");
    fclose(fp);
}

void searchMedicine(struct medicine arr[], int n, char searchName[]) {
    FILE *fp;
    int found=0;
    fp=fopen("medical-store.txt", "r");
    printf("\n                                           Medicines Matching your search\n");
    printf(" =======================================================================================================\n");
    printf("|                          MEDICINE NAME                          |  BATCH NO  |   COMPANY  |   PRICE   | QUANTITY  |\n");
    printf(" -------------------------------------------------------------------------------------------------------\n");
    while(!feof(fp)){
         fscanf(fp, "%s %s %s %f %d\n", &arr[n].name, &arr[n].batch, &arr[n].company, &arr[n].price, &arr[n].quantity);
         if(strcmp(arr[n].name, searchName)==0) {
            printf("|%-65s|%-11s|%-12s|%-11.2f|%-11d|\n", arr[n].name, arr[n].batch, arr[n].company, arr[n].price, arr[n].quantity);
            found=1;
         }
    } 
    printf(" --------------------------------------------------------------------------------------------------------\n");
    fclose(fp);
    if(found==0)
         printf("\n Medicine not found!");
}

void updateMedicine(struct medicine arr[], int n, char batchNum[]) {
    int i, found=0;
    FILE *fp, *fp1;
    fp=fopen("medical-store.txt", "r");
    fp1=fopen("temp.txt", "w");
    while(!feof(fp)){
         fscanf(fp, "%s %s %s %f %d\n", &arr[n].name, &arr[n].batch, &arr[n].company, &arr[n].price, &arr[n].quantity);
         if(strcmp(arr[n].batch, batchNum)==0) {
            printf("\n ------------------------Current Medicine Details-----------------------\n");
            printf("\n Medicine Name: %s", arr[n].name);
            printf("\n Batch number: %s", arr[n].batch);
            printf("\n Company: %s", arr[n].company);
            printf("\n Price: %.2f", arr[n].price);
            printf("\n Quantity: %d", arr[n].quantity);
            printf("\n\n ------------------------Enter new Details------------------------\n");
            printf("\n Enter Medicine Name: ");
            fflush(stdin);
            gets(arr[n].name);
            printf("\n Enter batch number: ");
            fflush(stdin);
            gets(arr[n].batch);
            printf("\n Enter Company: ");
            fflush(stdin);
            gets(arr[n].company);
            printf("\n Enter Price: ");
            scanf("%f", &arr[n].price);
            printf("\n Enter quantity: ");
            scanf("%d", &arr[n].quantity);
            fprintf(fp1, "%s %s %s %.2f %d\n", arr[n].name, arr[n].batch, arr[n].company, arr[n].price, arr[n].quantity);
            found=1;
            printf("\n Medicine details Updated successfully!");
         }
         else
            fprintf(fp1, "%s %s %s %.2f %d\n", arr[n].name, arr[n].batch, arr[n].company, arr[n].price, arr[n].quantity);
    }
    fclose(fp);
    fclose(fp1);
    remove("medical-store.txt");
    rename("temp.txt", "medical-store.txt");
    if(found==0)
         printf("\n Medicine not found!");
}

void deleteMedicine(struct medicine arr[], int *n, char batchNum[]) {
    int i, found=0;
    FILE *fp, *fp1;
    fp=fopen("medical-store.txt", "r");
    fp1=fopen("temp.txt", "w");
    while(!feof(fp)){
        fscanf(fp, "%s %s %s %f %d\n", &arr[*n].name, &arr[*n].batch, &arr[*n].company, &arr[*n].price, &arr[*n].quantity);
        if(strcmp(arr[*n].batch, batchNum)!=0)
            fprintf(fp1, "%s %s %s %.2f %d\n", arr[*n].name, arr[*n].batch, arr[*n].company, arr[*n].price, arr[*n].quantity);
        else{
            found=1;
            printf("\n Medicine deleted successfully!");
         }
         *n=*n+1;
    }
    fclose(fp);
    fclose(fp1);
    remove("medical-store.txt");
    rename("temp.txt", "medical-store.txt");
    if(found==0)
         printf("\n Medicine not found!");
}