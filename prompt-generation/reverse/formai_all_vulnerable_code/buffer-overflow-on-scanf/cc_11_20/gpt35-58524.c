//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include<stdio.h>
#include<math.h>

// Function to convert binary to decimal
int bintodec(long long bin) {

int dec=0,i=0,rem;

while(bin!=0) {
rem=bin%10;
bin/=10;
dec+=rem*pow(2,i);
++i;
}

return dec;
}

// Function to convert decimal to binary
long long dectobin(int dec) {

int rem,i=1;
long long bin=0;

while(dec!=0) {
rem=dec%2;
dec/=2;
bin+=rem*i;
i*=10;
}

return bin;
}

// Main Function
int main() {

int n,a[100],i,j,spl,subnet;
long long bin[4],mask=0;
char c;

printf("\nEnter the IP address in binary format: ");
for(i=0;i<4;i++) {

scanf("%lld",&bin[i]);

// Converting 8 bit binary to decimal
a[i]=bintodec(bin[i]);

if(i!=3) {
printf(".");
}
}

printf("\nEnter the default subnet mask in binary format: ");
for(i=0;i<4;i++) {

scanf("%lld",&bin[i]);

// Converting 8 bit binary to decimal
if(i==0) {
spl=bintodec(bin[i]);
if(spl<128) {
subnet=0;
} else if(spl>=128 && spl<192) {
subnet=1;
} else if(spl>=192 && spl<224) {
subnet=2;
} else if(spl>=224 && spl<240) {
subnet=3;
} else if(spl>=240 && spl<248) {
subnet=4;
} else if(spl>=248 && spl<252) {
subnet=5;
} else if(spl>=252 && spl<254) {
subnet=6;
} else {
subnet=7;
}
}

// Creating complete mask
mask=mask|bin[i];

if(i!=3) {
printf(".");
}
}

// Creating Subnet mask based on user input
int sc,sub[4]={0,0,0,0};

printf("\nEnter the number of bits to be borrowed for subnet: ");
scanf("%d",&sc);

for(i=0;i<4;i++) {
if(sc>8) {
sub[i]=255;
sc=sc-8;
} else {
if(sc==8) {
sub[i]=255;
} else {
int temp=8-sc;
for(j=0;j<temp;j++) {
sub[i]=sub[i]+pow(2,7-j);
}
sc=0;
}
}
}

// Displaying the details of IP address and subnet mask
printf("\nIP Address is: ");
for(i=0;i<4;i++) {
printf("%d",a[i]);
if(i!=3) {
printf(".");
}
}
printf("\nSubnet Mask is: ");
for(i=0;i<4;i++) {
printf("%d",sub[i]);
if(i!=3) {
printf(".");
}
}
printf("\nNetwork Portion of IP Address is: ");
for(i=0;i<4;i++) {
printf("%d",a[i]&sub[i]);
if(i!=3) {
printf(".");
}
}
printf("\nHost Portion of IP Address is: ");
for(i=0;i<4;i++) {
printf("%d",a[i]&(~sub[i]));
if(i!=3) {
printf(".");
}
}
int totalbits=32,hostbits=sc,nbits=totalbits-subnet-sc;
int netid=totalbits-sc,hostid=0;
long long hosts=0;

for(i=0;i<hostbits;i++) {
hosts=hosts+pow(2,i);
}

// Displaying the details of subnetting
printf("\n\n");
for(i=0;i<4;i++) {
bin[i]=dectobin(sub[i]);
}

printf("Mask: %lld.%lld.%lld.%lld\n",bin[0],bin[1],bin[2],bin[3]);
printf("Subnet Bits: %d\n",sc);
printf("Number of Subnets: %d\n",pow(2,sc));
printf("Number of Hosts: %lld\n",hosts);

printf("\nSubnet ID\tFirst Address\tLast Address\tBroadcast Address\n");

for(i=0;i<pow(2,sc);i++) {
bin[netid]=dectobin(a[3]);
bin[netid-1]=dectobin(a[2]);
bin[netid-2]=dectobin(a[1]);
bin[netid-3]=dectobin(a[0]);

for(j=0;j<sc;j++) {
if(i & (1<<j)) {
bin[hostid]=bin[hostid]+pow(2,7-j);
}
}
for(j=0;j<4;j++) {
printf("%d.",bintodec(bin[j]));
}
printf("\t");
bin[hostid]=bin[hostid]+1;
for(j=0;j<4;j++) {
printf("%d.",bintodec(bin[j]));
}
bin[hostid]=bin[hostid]-1;
bin[hostid+1]=bin[hostid+1]+1;
if(bin[hostid+1]>=256) {
bin[hostid+1]=bin[hostid+1]-256;
bin[hostid+2]=bin[hostid+2]+1;
if(bin[hostid+2]>=256) {
bin[hostid+2]=bin[hostid+2]-256;
bin[hostid+3]=bin[hostid+3]+1;
}
}
for(j=0;j<4;j++) {
printf("%d.",bintodec(bin[j]));
}
bin[hostid+1]=bin[hostid+1]-1;
bin[hostid+2]=bin[hostid+2]-1;
bin[hostid+3]=bin[hostid+3]+1;
if(bin[hostid+3]>=256) {
bin[hostid+3]=bin[hostid+3]-256;
bin[hostid+2]=bin[hostid+2]+1;
if(bin[hostid+2]>=256) {
bin[hostid+2]=bin[hostid+2]-256;
bin[hostid+1]=bin[hostid+1]+1;
}
}
for(j=0;j<4;j++) {
printf("%d",bintodec(bin[j]));
if(j!=3) {
printf(".");
}
}
printf("\n");
}

return 0;
}