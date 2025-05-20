//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cafeItem {
   char item_name[50];
   int item_price;
};

struct cafeItem cafe_menu_items[100];

void addItemsToMenu() {
   strcpy(cafe_menu_items[0].item_name,"Black Coffee");
   cafe_menu_items[0].item_price=10;

   strcpy(cafe_menu_items[1].item_name,"Cappuccino");
   cafe_menu_items[1].item_price=15;

   strcpy(cafe_menu_items[2].item_name,"Espresso");
   cafe_menu_items[2].item_price=12;

   strcpy(cafe_menu_items[3].item_name,"Latte");
   cafe_menu_items[3].item_price=17;

   strcpy(cafe_menu_items[4].item_name,"Mocha");
   cafe_menu_items[4].item_price=20;

   strcpy(cafe_menu_items[5].item_name,"Tea");
   cafe_menu_items[5].item_price=8;

   printf("Added all the items to the menu. \n");
}

void printMenu() {
   printf("================================================= \n");
   printf("=============== CAFE MENU ======================= \n");
   printf("================================================= \n");
   for (int i=0;i<6;i++) {
      printf(" %-16s  |   %3d rupees \n", cafe_menu_items[i].item_name,cafe_menu_items[i].item_price);
   }
   printf("================================================= \n");
}

void generateBill(int num_items, int item_array[]) {
   int total_bill = 0;
   printf("\n\n============================================\n");
   printf("   CAFE BILL\n");
   printf("============================================\n");
   for (int i=0;i<num_items;i++) {
      int item_index = item_array[i]-1;
      total_bill += cafe_menu_items[item_index].item_price;

      printf(" %-16s  |  %3d rupees\n", cafe_menu_items[item_index].item_name, cafe_menu_items[item_index].item_price);
   }
   printf("============================================\n");
   printf("TOTAL:  %d rupees\n", total_bill);
   printf("============================================\n");
}


int main() {
   printf("Initializing cafe billing system\n");

   addItemsToMenu();

   printf("\nPrinting the cafe menu\n");
   printMenu();

   printf("\nPlease choose your items from the menu by entering item number\n");
   int num_items = 0;
   int item_nums[100];
   while (1) {
      int item_num;
      printf("\nEnter item %d code or enter 0 to finish: ", num_items+1);
      scanf("%d", &item_num);
      if (item_num==0) break;

      item_nums[num_items] = item_num;
      num_items++;
   }

   generateBill(num_items, item_nums);
   
   return 0;
}