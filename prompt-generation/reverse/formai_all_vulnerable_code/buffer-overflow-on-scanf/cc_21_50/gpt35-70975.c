//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include<stdio.h>

int main() {
   int day, month, year;

   printf("Enter date in the format (dd/mm/yyyy): ");
   scanf("%d/%d/%d",&day,&month,&year);

   if(day<1 || day>31) {
      printf("Invalid day!");
      return -1;
   }

   if(month<1 || month>12) {
      printf("Invalid month!");
      return -1;
   }

   if(year<1900 || year>2100) {
      printf("Invalid year!");
      return -1;
   }

   switch(month) {
      case 2:
         if((year%4==0 && year%100!=0) || year%400==0) {
            if(day>29) {
               printf("Invalid date!");
               return -1;
            }
         } else {
            if(day>28) {
               printf("Invalid date!");
               return -1;
            }
         }
         break;

      case 4:
      case 6:
      case 9:
      case 11:
         if(day>30) {
            printf("Invalid date!");
            return -1;
         }
         break;

      default:
         break;
   }

   printf("The converted date is: ");

   switch(month) {
      case 1:
         printf("January %d, %d", day, year);
         break;

      case 2:
         printf("February %d, %d", day, year);
         break;

      case 3:
         printf("March %d, %d", day, year);
         break;

      case 4:
         printf("April %d, %d", day, year);
         break;

      case 5:
         printf("May %d, %d", day, year);
         break;

      case 6:
         printf("June %d, %d", day, year);
         break;

      case 7:
         printf("July %d, %d", day, year);
         break;

      case 8:
         printf("August %d, %d", day, year);
         break;

      case 9:
         printf("September %d, %d", day, year);
         break;

      case 10:
         printf("October %d, %d", day, year);
         break;

      case 11:
         printf("November %d, %d", day, year);
         break;

      case 12:
         printf("December %d, %d", day, year);
         break;

      default:
         break;
   }

   return 0;
}