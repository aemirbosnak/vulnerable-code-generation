//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct network {
   char ssid[20];
   int signal_strength;
};

int main() {
   int choice, i, j, count = 0;
   struct network networks[10];

   printf("Welcome to Wi-Fi Signal Strength Analyzer\n\n");
   while(1) {
       printf("Please choose an option:\n");
       printf("1. Add a network\n");
       printf("2. View all networks\n");
       printf("3. View strongest network\n");
       printf("4. Exit\n");
       scanf("%d", &choice);

       switch(choice) {
           case 1:
               printf("\n-- Add a network --\n");
               printf("Enter SSID of the network: ");
               scanf("%s", networks[count].ssid);
               printf("Enter signal strength (in dBm): ");
               scanf("%d", &networks[count].signal_strength);
               count++;
               break;

           case 2:
               printf("\n-- All Networks --\n");
               if(count == 0) {
                   printf("No networks added yet.\n");
                   break;
               }
               for(i=0; i<count; i++) {
                   printf("Network %d\n", i+1);
                   printf("    SSID: %s\n", networks[i].ssid);
                   printf("    Signal Strength: %d dBm\n", networks[i].signal_strength);
               }
               break;

           case 3:
               printf("\n-- Strongest Network --\n");
               if(count == 0) {
                   printf("No networks added yet.\n");
                   break;
               }
               int max_strength = -100;
               for(i=0; i<count; i++) {
                   if(networks[i].signal_strength > max_strength) {
                       max_strength = networks[i].signal_strength;
                       j = i;
                   }
               }
               printf("Strongest Network:\n");
               printf("    SSID: %s\n", networks[j].ssid);
               printf("    Signal Strength: %d dBm\n", networks[j].signal_strength);
               break;

           case 4:
               printf("\nExiting program...");
               exit(0);

           default:
               printf("\nInvalid choice. Please try again.\n");
               break;
       }
   }
   return 0;
}