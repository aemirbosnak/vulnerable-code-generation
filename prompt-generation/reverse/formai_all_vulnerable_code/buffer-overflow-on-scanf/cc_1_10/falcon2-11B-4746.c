//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

struct menu {
	int id;
	char *name;
	float price;
};

struct order {
	int id;
	char *name;
	struct menu *menu;
	float total;
};

int main() {
	struct order orders[100];
	struct menu menu[100];
	int i,j,n;
	
	printf("Welcome to the Medieval Cafe!\n");
	printf("Please select a dish from the menu:\n");
	
	for(i=0; i<100; i++) {
		menu[i].id = i+1;
		scanf("%s", menu[i].name);
		scanf("%f", &menu[i].price);
	}
	
	printf("What would you like to order?\n");
	scanf("%s", orders[0].name);
	scanf("%f", &orders[0].total);
	orders[0].menu = &menu[0];
	
	for(i=1; i<100; i++) {
		printf("Order %d: ", i);
		scanf("%s", orders[i].name);
		scanf("%f", &orders[i].total);
		orders[i].menu = &menu[i-1];
	}
	
	for(i=0; i<100; i++) {
		for(j=0; j<i; j++) {
			if(orders[i].menu->name == orders[j].menu->name && orders[i].menu->price == orders[j].menu->price) {
				printf("You cannot order two of the same dishes.\n");
				continue;
			}
		}
		
		printf("Order %d: %s\n", i+1, orders[i].name);
		printf("Total: %f\n", orders[i].total);
	}
	
	return 0;
}