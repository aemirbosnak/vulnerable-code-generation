//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include <stdio.h> 

#include <stdlib.h> 

#include <string.h> 

struct medicine { char name[50]; int quantity; float price; }; 

void print_menu(void) { 

system("cls"); // to clear the screen

printf("\nMedical Store Management System\n\n");

printf("1. Add Medicine\n"); 

printf("2. View Medicine\n"); 

printf("3. Update Medicine\n"); 

printf("4. Delete Medicine\n"); 

printf("5. Exit\n"); 

return; 

} 

void add_medicine(struct medicine med[], int *mcount) { 

system("cls"); 

if(*mcount == 50) { 

printf("**** No more medicines can be added ****\n\n"); 

return; 

} 

int med_id = *mcount; 

printf("Enter name of medicine: "); 

scanf("%s", med[med_id].name); 

printf("Enter quantity of medicine: "); 

scanf("%d", &med[med_id].quantity); 

printf("Enter Price of medicine: "); 

scanf("%f", &med[med_id].price); 

(*mcount)++; 

printf("\n**** Medicine added successfully ****\n\n"); 

return; 

} 

void view_medicine(struct medicine med[], int *mcount) { 

system("cls"); 

if(*mcount == 0) { 

printf("**** No medicines available ****\n\n"); 

return; 

} 

for(int i=0; i<*mcount; i++) { 

printf("\nMedicine ID : %d\n", i+1); 

printf("Name : %s\n", med[i].name); 

printf("Quantity : %d\n", med[i].quantity); 

printf("Price : %.2f", med[i].price); 

printf("\n***************************************"); 

} 

printf("\n"); 

return; 

} 

void update_medicine(struct medicine med[], int *mcount) { 

system("cls"); 

if(*mcount == 0) { 

printf("**** No medicines available ****\n\n"); 

return; 

} 

int med_id = -1; 

printf("Enter medicine ID to update: "); 

scanf("%d", &med_id); 

if(med_id <0 || med_id >= *mcount) { 

printf("**** Invalid medicine ID ****\n\n"); 

return; 

} 

printf("Enter name of medicine: "); 

scanf("%s", med[med_id].name); 

printf("Enter quantity of medicine: "); 

scanf("%d", &med[med_id].quantity); 

printf("Enter price of medicine: "); 

scanf("%f", &med[med_id].price); 

printf("\n**** Medicine updated successfully ****\n\n"); 

return; 

} 

void delete_medicine(struct medicine med[], int *mcount) { 

system("cls"); 

if(*mcount == 0) { 

printf("**** No medicines available ****\n\n"); 

return; 

} 

int med_id = -1; 

printf("Enter medicine ID to delete: "); 

scanf("%d", &med_id); 

if(med_id <0 || med_id >= *mcount) { 

printf("**** Invalid medicine ID ****\n\n"); 

return; 

} 

for(int i=med_id+1; i<*mcount; i++) { 

strcpy(med[i-1].name, med[i].name); 

med[i-1].quantity = med[i].quantity; 

med[i-1].price = med[i].price; 

} 

(*mcount)--; 

printf("\n**** Medicine deleted successfully ****\n\n"); 

return; 

} 

int main(void) { 

int selection; 

struct medicine med[50]; 

int mcount = 0; 

do { 

print_menu(); 

printf("Enter selection: "); 

scanf("%d", &selection); 

switch(selection) { 

case 1: 

add_medicine(med, &mcount); 

break; 

case 2: 

view_medicine(med, &mcount); 

break; 

case 3: 

update_medicine(med, &mcount); 

break; 

case 4: 

delete_medicine(med, &mcount); 

break; 

case 5: 

printf("\n**** Thank you for using Medical Store Management System ****\n\n"); 

exit(1); 

break; 

default: 

printf("\n**** Invalid selection ****\n\n"); 

} 

system("pause"); //To hold the screen till any key is pressed 

} while(selection != 5); 

return 0; 

}