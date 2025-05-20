//FormAI DATASET v1.0 Category: Phone Book ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct phonebook {
char name[20];
long int number;
}PB;

int main() {
PB p[100];
char name[20];
long int number;
int i = 0, j = 0, n = 0;

while (1) {
int ch;
printf("\n\n-----------------------PHONEBOOK-----------------------");
printf("\n\nPlease Choose an Option:\n 1. Add Contact\n 2. List Contacts\n 3. Search Contact\n 4. Modify Contact\n 5. Delete Contact\n 6. Quit\n\nEnter your Option: ");
scanf("%d", &ch);
switch (ch) {
case 1:
printf("\nEnter Name: ");
scanf("%s", &p[i].name);
printf("\nEnter Phone Number: ");
scanf("%ld", &p[i].number);
printf("\nContact successfully added!\n");
i++;
break;

case 2:
printf("\n---------------------------\n");
printf("\n\tCONTACT LIST\n\n");
if (i == 0)
printf("No Contacts found!\n");
else {
for (j = 0; j < i; j++) {
printf("%d. Name: %s\nNumber: %ld\n", j + 1, p[j].name, p[j].number);
}
}
break;

case 3:
printf("\nEnter Name to search: ");
scanf("%s", &name);
for (j = 0; j < i; j++) {
if (strcmp(name, p[j].name) == 0) {
printf("\nMatch Found!\n");
printf("Name: %s\nNumber: %ld\n", p[j].name, p[j].number);
n = 1;
break;
}
}
if (n == 0)
printf("No Match Found for %s\n", name);
n = 0;
break;

case 4:
printf("\nEnter Name to modify: ");
scanf("%s", &name);
for (j = 0; j < i; j++) {
if (strcmp(name, p[j].name) == 0) {
printf("\nMatch Found!\n");
printf("Name: %s\nNumber: %ld\n", p[j].name, p[j].number);
printf("Enter New Name: ");
scanf("%s", &p[j].name);
printf("Enter New Number: ");
scanf("%ld", &p[j].number);
printf("\nContact Modified!\n");
n = 1;
break;
}
}
if (n == 0)
printf("\nNo Match Found for %s\n", name);
n = 0;
break;

case 5:
printf("\nEnter Name to delete: ");
scanf("%s", &name);
for (j = 0; j < i; j++) {
if (strcmp(name, p[j].name) == 0) {
printf("\nMatch Found!\n");
printf("Name: %s\nNumber: %ld\n", p[j].name, p[j].number);
printf("Are you sure you want to delete this contact? (y/n): ");
char c;
scanf(" %c", &c);
if (c == 'y' || c == 'Y') {
for (int k = j; k < (i - 1); k++) {
p[k] = p[k + 1];
}
printf("\nContact Deleted!\n");
i--;
n = 1;
break;
}
else {
n = 1;
break;
}
}
}
if (n == 0)
printf("\nNo Match Found for %s\n", name);
n = 0;
break;

case 6:
printf("\nThank you for using the Phonebook!\n");
return 0;

default:
printf("\nInvalid Input! Please Try Again.\n");
}
}
return 0;
}