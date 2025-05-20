//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(NULL)); // seed the random number generator

   int network_quality = 0; // initialize network quality to 0

   // medieval-style introduction
   printf("Greetings, noble network administrator! Thou art tasked with monitoring the quality of our fair kingdom's network.\n");
   printf("Fear not, for I have created a tool to aid thee in thy quest!\n\n");

   while(1) // loop forever
   {
      // simulate network activity
      int packets_sent = rand() % 100; // randomly generate number of packets sent
      int packets_received = rand() % 100; // randomly generate number of packets received

      // calculate network quality
      network_quality = ((float)packets_received / (float)packets_sent) * 100;

      // display results
      printf("Current network quality: %d\n", network_quality);

      // determine action to take based on network quality
      if(network_quality < 50)
      {
         printf("Verily, the network doth falter! Might I suggest checking the cabling and resetting the switches?\n");
      }
      else if(network_quality < 70)
      {
         printf("The network performeth adequately, but couldst thou not optimize it further? Perhaps a firmware update is in order.\n");
      }
      else if(network_quality < 90)
      {
         printf("Truly, the network is a wonder to behold! Yet still, there is room for improvement. A load balancer might be of use in this scenario.\n");
      }
      else
      {
         printf("Huzzah! The network is in top form! So confident am I in thy abilities, I shall bestow upon thee a small bonus! Enjoy the fruits of thy labor!\n");
         break; // exit the program with no errors
      }

      // pause for dramatic effect
      printf("\nWait a moment whilst I consult the ancient scrolls...\n\n");
      sleep(5); // sleep for 5 seconds
   }

   return 0;
}