//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cryptic
#include<stdio.h>

void main(){
   int ip1,ip2,ip3,ip4,submask,c,a=0,b=0,cnt=0;
   int i,j;

   printf("Enter IP Address: ");
   scanf("%d.%d.%d.%d",&ip1,&ip2,&ip3,&ip4);

   printf("\nEnter Subnet Mask: ");
   scanf("%d",&submask);

   c=submask/8; 

   if(submask%8!=0){
     switch(submask%8){
        case 1:
               a=128;
               break;
        case 2:
               a=192;
               break;
        case 3:
               a=224;
               break;
        case 4:
               a=240;
               break;
        case 5:
               a=248;
               break;
        case 6:
               a=252;
               break;
        case 7:
               a=254;
               break;
     }
     b=255^a;
   }

   for(i=1;i<=c;i++){
      printf("%d.",ip1);
      ip1=0;

      cnt++;
      if(cnt==4)
         break;
   }

   if(cnt<4){
      if(a==0)
         printf("%d",ip1);
      else
         printf("%d.",ip1&a);
      cnt++;

      if(cnt<4){
         for(i=1;i<=c;i++){
            printf("0.");

            cnt++;

            if(cnt==4)
               break;
         }
      }

      if(cnt<4){
         printf("%d",b);

         cnt++;

         if(cnt<4){
            for(i=1;i<=(4-cnt);i++){
               printf(".0");
            }
         }
      }
   }

   printf("\n");
}