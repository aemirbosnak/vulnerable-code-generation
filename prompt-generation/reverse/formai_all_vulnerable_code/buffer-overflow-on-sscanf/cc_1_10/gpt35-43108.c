//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 10

int matrix[SIZE][SIZE];
char devices[SIZE][10];
int device_count = 0;

int is_duplicate(char *dev_name){
    int i =0;
    for(i=0;i<device_count;i++){
        if(strcmp(dev_name, devices[i])==0){
            return i+1;
        }
    }
    return 0;
}
void add_device(char *dev_name){
    strcpy(devices[device_count], dev_name);
    device_count++;
}

void connect(char *dev1, char *dev2){
  int num1=0,num2=0;
  int pos1 = is_duplicate(dev1);
  if(!pos1){
    num1=device_count ++; 
    add_device(dev1);
  }
  else{
    num1=pos1-1;
  }
  int pos2=is_duplicate(dev2);
  if(!pos2){
    num2=device_count ++;
    add_device(dev2);
  }
  else{
    num2=pos2-1;
  }
  matrix[num1][num2]=1;
  matrix[num2][num1]=1;

}
void display(){
    int i=0, j=0;
    printf("\n-------------------------\n");
    printf("   Network Topology Mapper\n");
    printf("-------------------------\n\n");
    for(i=0;i<device_count;i++){
        printf("%10s", devices[i]);
    }
    printf("\n");
    for(i=0;i<device_count;i++){
        printf("%10s", devices[i]);
        for(j=0;j<device_count;j++){
            printf("%10d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char buffer[128];
    char dev1[10], dev2[10];
    int flag = 1;
    while(flag){
        printf("Enter the devices to connect (device1 device2): ");
        fgets(buffer, sizeof(buffer), stdin);
        if(buffer[0]=='\n') {
            flag = 0;
            break;
        }
        sscanf(buffer,"%s %s",dev1,dev2);
        connect(dev1,dev2);
    }
    display();
    return 0;
}