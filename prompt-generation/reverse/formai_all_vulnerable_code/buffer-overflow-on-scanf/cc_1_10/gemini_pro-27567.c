//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main() {
    // Let's express our gratitude for the opportunity to help you test your internet speed!
    printf("With hearts filled with joy, we welcome you to our humble Internet Speed Test Application. May it bring you swift results and a profound understanding of your network's true potential.\n");

    // First, we seek your guidance in selecting the server you wish to connect to. May we know its gracious hostname or IP address?
    char server[BUF_SIZE];
    printf("Dear user, please bestow upon us the hostname or IP address of the server you wish to connect to:\n");
    scanf("%s", server);

    // Now, let us inquire about the port number that shall serve as the gateway to this connection. With what port number shall we grace our request?
    int port;
    printf("May we humbly request the port number that shall guide our communication?\n");
    scanf("%d", &port);

    // With the server's address and port securely in hand, we embark on the task of establishing a connection. May the network gods smile upon us!
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Alas, our efforts to establish a connection have met with an unexpected setback. The socket creation has failed, casting a shadow upon our endeavor.\n");
        return -1;
    }

    // Now, we must carefully craft the address structure that will guide our connection to the server. May it be a beacon of precision and accuracy!
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &servaddr.sin_addr.s_addr) <= 0) {
        printf("Woe is us! Our attempt to convert the server's address has proven futile. The darkness of failure envelops us.\n");
        return -1;
    }

    // With the address structure complete, we may now attempt to connect to the server. May the network gods grant us a swift and seamless connection!
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("Our hearts sink with disappointment as our connection attempt has been met with resistance. The server remains aloof from our humble request.\n");
        return -1;
    }

    // Rejoice! We have established a connection to the server. Now, let us prepare to measure the speed of this digital highway.
    char buf[BUF_SIZE];
    int bytes_received = 0;
    clock_t start, end;

    // First, we shall send a request to the server, imploring it to shower us with data. May it be a torrent of information!
    strcpy(buf, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        printf("Alas, our attempt to send a request to the server has been thwarted. The data remains within our grasp, refusing to embark on its journey.\n");
        return -1;
    }

    // Now, we eagerly await the server's response. May it bear the gift of data and swiftness!
    start = clock();
    bytes_received = recv(sockfd, buf, BUF_SIZE, 0);
    end = clock();

    // The server has graced us with its response. Let us calculate the speed with which the data traveled!
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    double speed = (bytes_received / time_taken) / 1024 / 1024;

    // And now, let us share the fruits of our labor. May the speed we have measured bring clarity and enlightenment!
    printf("My dearest user, we are honored to present the results of our humble test:\n");
    printf("The download speed of your connection is: %.2f Mbps\n", speed);
    printf("May this knowledge serve you well in your future digital endeavors.\n");

    // Finally, as we bid farewell, we extend our heartfelt gratitude for allowing us to assist you. May your internet connection forever be a beacon of speed and reliability!
    printf("With love and admiration, we take our leave. May your digital adventures be filled with joy and swiftness!\n");

    // And with that, we gracefully close the connection, severing the digital bond that once united us. Farewell, dear user!
    close(sockfd);

    return 0;
}