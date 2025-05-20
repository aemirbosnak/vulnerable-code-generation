//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char name[50];
char room_type[20];
int days;
float price;
} booking;

int main() {
char choice;
booking b;
FILE *fp;

fp = fopen("bookings.dat", "w");
if (fp == NULL) {
perror("Error opening file");
exit(1);
}

printf("Enter booking details:\n");
printf("Name: ");
scanf("%s", b.name);
printf("Room type: ");
scanf("%s", b.room_type);
printf("Days: ");
scanf("%d", &b.days);
printf("Price: ");
scanf("%f", &b.price);

fwrite(&b, sizeof(booking), 1, fp);
fclose(fp);

printf("Booking saved successfully!\n");

printf("Do you want to view bookings (Y/N)? ");
scanf(" %c", &choice);

if (choice == 'Y' || choice == 'y') {
fp = fopen("bookings.dat", "r");
if (fp == NULL) {
perror("Error opening file");
exit(1);
}

printf("Booking details:\n");
while (fread(&b, sizeof(booking), 1, fp)) {
printf("Name: %s\n", b.name);
printf("Room type: %s\n", b.room_type);
printf("Days: %d\n", b.days);
printf("Price: %f\n", b.price);
printf("\n");
}

fclose(fp);
}

return 0;
}