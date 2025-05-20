//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include<stdio.h>  
#include<string.h>  

void alert(char *msg)  
{  
  printf("ALERT: %s", msg);  
} 

int main()  
{  
  //initialize variables  
  char packet[100];  
  char senderIP[20];  
  char receiverIP[20];  
  int packetSize;  
  int numPackets = 0;  
  int seconds = 0;  
  int bytesPerSecond = 0;  
  int totalBytes = 0;  
  int numInvalidPackets = 0;  
  int numIntrusions = 0;  
  int bytesSinceLastAlert = 0;  
    
  //read packets from input  
  while (fgets(packet, 100, stdin) != NULL)  
  {  
    //increment packet counter  
    numPackets++;  
      
    //extract packet information  
    sscanf(packet, "%s %s %d", senderIP, receiverIP, &packetSize);  
      
    //check if packet is valid  
    if (packetSize < 0 || packetSize > 1500)  
    {  
      //increment counter for invalid packets  
      numInvalidPackets++;  
        
      //check if invalid packets exceed threshold  
      if (numInvalidPackets > 10)  
      {  
        //raise alert for too many invalid packets  
        alert("Too many invalid packets detected");  
          
        //reset counter for invalid packets  
        numInvalidPackets = 0;  
      }  
    }  
    else  
    {  
      //calculate bytes per second  
      bytesPerSecond = packetSize / seconds;  
        
      //check if bytes per second is greater than threshold  
      if (bytesPerSecond > 1000)  
      {  
        //raise alert for high traffic  
        alert("High traffic detected");  
          
        //reset bytes since last alert  
        bytesSinceLastAlert = 0;  
      }  
        
      //increment total bytes counter  
      totalBytes += packetSize;  
        
      //increment bytes since last alert counter  
      bytesSinceLastAlert += packetSize;  
        
      //check if bytes since last alert exceed threshold  
      if (bytesSinceLastAlert > 1000000)  
      {  
        //raise alert for excessive data transfer  
        alert("Excessive data transfer detected");  
          
        //reset bytes since last alert  
        bytesSinceLastAlert = 0;  
      }  
        
      //check if sender and receiver are different  
      if (strcmp(senderIP, receiverIP) != 0)  
      {  
        //increment counter for potential intrusion  
        numIntrusions++;  
          
        //check if potential intrusions exceed threshold  
        if (numIntrusions > 5)  
        {  
          //raise alert for potential intrusion  
          alert("Potential intrusion detected");  
            
          //reset counter for potential intrusions  
          numIntrusions = 0;  
        }  
      }  
    }  
      
    //increment seconds counter  
    seconds++;  
  }  
    
  return 0;  
}