//FormAI DATASET v1.0 Category: Smart home light control ; Style: complete
#include<stdio.h>

#define ON 1
#define OFF 0

typedef struct {
   int light1;
   int light2;
   int light3;
} SmartHomeLights;

void display_menu() {
   printf("\n1. Turn on light 1\n");
   printf("2. Turn on light 2\n");
   printf("3. Turn on light 3\n");
   printf("4. Turn off light 1\n");
   printf("5. Turn off light 2\n");
   printf("6. Turn off light 3\n");
   printf("0. Quit\n");
}

void turn_on_light(int light, SmartHomeLights* lights) {
   switch (light) {
      case 1:
         lights->light1 = ON;
         printf("Light 1 turned on.\n");
         break;
      case 2:
         lights->light2 = ON;
         printf("Light 2 turned on.\n");
         break;
      case 3:
         lights->light3 = ON;
         printf("Light 3 turned on.\n");
         break;
      default:
         printf("Invalid light number.\n");
         break;
   }
}

void turn_off_light(int light, SmartHomeLights* lights) {
   switch (light) {
      case 1:
         lights->light1 = OFF;
         printf("Light 1 turned off.\n");
         break;
      case 2:
         lights->light2 = OFF;
         printf("Light 2 turned off.\n");
         break;
      case 3:
         lights->light3 = OFF;
         printf("Light 3 turned off.\n");
         break;
      default:
         printf("Invalid light number.\n");
         break;
   }
}

int main() {
   SmartHomeLights lights = {OFF, OFF, OFF};
   int choice;

   do {
      display_menu();
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            turn_on_light(1, &lights);
            break;
         case 2:
            turn_on_light(2, &lights);
            break;
         case 3:
            turn_on_light(3, &lights);
            break;
         case 4:
            turn_off_light(1, &lights);
            break;
         case 5:
            turn_off_light(2, &lights);
            break;
         case 6:
            turn_off_light(3, &lights);
            break;
         case 0:
            printf("Goodbye!\n");
            break;
         default:
            printf("Invalid choice.\n");
            break;
      }

   } while (choice != 0);

   return 0;
}